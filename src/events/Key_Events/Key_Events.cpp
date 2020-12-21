#include <iomanip>
#include <sstream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Debug_Window : public Fl_Window {
  public:
    Debug_Window() : Fl_Window(200, 100, 300, 300, "Debug") {
      resizable(text_display);
      auto screen_num = Fl::screen_num(x(), y());
      auto screen_x = 0, screen_y = 0, screen_width = 0, screen_height = 0;
      Fl::screen_xywh(screen_x, screen_y, screen_width, screen_height);
      resize(screen_x, screen_y + (screen_height / 3 * 2), screen_width, screen_height / 3);
      text_display.buffer(&text_buffer);
      show();
    }
    
    void append_line(const std::string& line) {
      text_buffer.append(line.c_str());
      text_buffer.append("\n");
      text_display.scroll(text_buffer.count_lines(0, text_buffer.length()), 0);
    }
    
    void hide() override {}
    
  private:
    Fl_Text_Buffer text_buffer;
    Fl_Text_Display text_display {0, 0, 300, 300};
  };

  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Key events example") {}
    
    int handle(int event) override {
      using namespace std::literals;
      if (event == FL_KEYDOWN) debug.append_line("Key_Down = "s + key_to_string());
      if (event == FL_KEYDOWN && Fl::event_length() != 0) debug.append_line("Key_Press = {key_char='"s + Fl::event_text() + "'}"s);
      if (event == FL_KEYUP) debug.append_line("Key_Up = "s + key_to_string() + (modifiers_to_string() == "[none]" ? "\n"s : ""s));
      return Fl_Window::handle(event);
    }
    
    void hide() override {
      Fl_Window::hide();
      exit(0);
    }
    
  private:
    static std::string key_to_string() {
      std::stringstream ss;
      ss << "{key_code=0x" << std::hex << std::setfill('0') << std::setw(4) << Fl::event_key() << ", modifiers=" << modifiers_to_string() << "}";
      return ss.str();
    }

    static std::string modifiers_to_string() {
      std::stringstream ss;
      ss << "[";
      if (Fl::event_shift()) ss << "shift";
      if (Fl::event_ctrl()) ss << (ss.str() == "[" ? "" : ", ")  << "control";
      if (Fl::event_alt()) ss << (ss.str() == "[" ? "" : ", ")  << "alt";
      if (Fl::event_command()) ss << (ss.str() == "[" ? "" : ", ")  << "command";
      if (ss.str() == "[") ss << "none";
      ss << "]";
      return ss.str();
    }

    Fl_End end_this;
    Debug_Window debug;
  };
}

int main(int argc, char *argv[]) {
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
