#include <iomanip>
#include <sstream>
#include "Fl_Debug_Window.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::literals;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Key events example") {}
    
    int handle(int event) override {
      if (event == FL_KEYDOWN) debug.append_line(("Key_Down = "s + key_to_string()).c_str());
      if (event == FL_KEYDOWN && Fl::event_length() != 0) debug.append_line(("Key_Press = "s + key_char_to_string()).c_str());
      if (event == FL_KEYUP) {
        debug.append_line(("Key_Up = "s + key_to_string()).c_str());
        if (modifiers_to_string() == "[none]") debug.append_line("");
      }
      return Fl_Window::handle(event);
    }
    
    void hide() override {
      Fl_Window::hide();
      exit(0);
    }
    
  private:
    static string key_to_string() {
      stringstream ss;
      ss << "{key_code=0x" << hex << setfill('0') << setw(4) << Fl::event_key() << ", modifiers=" << modifiers_to_string() << "}";
      return ss.str();
    }
    
    static string key_char_to_string() {return std::string("{key_char='") + Fl::event_text() + std::string("'}");}
    
    static string modifiers_to_string() {
      if (!Fl::event_shift() && !Fl::event_ctrl() && !Fl::event_alt() && !Fl::event_command()) return "[none]";
      string result;
      if (Fl::event_shift()) result += "shift, ";
      if (Fl::event_ctrl()) result += "control, ";
      if (Fl::event_alt()) result += "alt, ";
      if (Fl::event_command()) result += "command, ";
      result.resize(result.size() - 2);
      return "[" + result + "]";
    }

    Fl_End end_this;
    Fl_Debug_Window debug;
  };
}

int main(int argc, char *argv[]) {
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
