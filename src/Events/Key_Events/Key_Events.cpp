#define TRACE
#include "Fl_Trace_Window.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <iomanip>
#include <sstream>

using namespace std;
using namespace std::literals;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Key events example"} {}
    
    auto handle(int event) noexcept -> int override {
      if (event == FL_KEYDOWN) trace.append_line(("Key_Down = "s + key_to_string()).c_str());
      if (event == FL_KEYDOWN && Fl::event_length() != 0) trace.append_line(("Key_Press = "s + key_char_to_string()).c_str());
      if (event == FL_KEYUP) {
        trace.append_line(("Key_Up = "s + key_to_string()).c_str());
        if (modifiers_to_string() == "[none]") trace.append_line("");
      }
      return Fl_Window::handle(event);
    }
    
    void hide() override {
      Fl_Window::hide();
      exit(0);
    }
    
  private:
    static string key_to_string() noexcept {
      auto ss = stringstream {};
      ss << "{key_code=0x" << hex << setfill('0') << setw(4) << Fl::event_key() << ", modifiers=" << modifiers_to_string() << "}";
      return ss.str();
    }
    
    static string key_char_to_string() noexcept {return std::string("{key_char='") + Fl::event_text() + std::string("'}");}
    
    static string modifiers_to_string() noexcept {
      auto result = string {};
      if (Fl::event_shift()) result += "shift, ";
      if (Fl::event_ctrl()) result += "control, ";
      if (Fl::event_alt()) result += "alt, ";
      if (Fl::event_command()) result += "command, ";
      if (result.size()) result.resize(result.size() - 2);
      else result = "none";
      return "[" + result + "]";
    }

    Fl_End end_this;
    Fl_Trace_Window trace;
  };
}

auto main(int argc, char *argv[]) -> int {
  Fl::add_handler([](int event) - >int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
