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
    Main_Window() : Fl_Window(200, 100, 300, 300, "Mouse events example") {}
    
    int handle(int event) override {
      if (Fl::event_x() >= 0 && Fl::event_x() < w() && Fl::event_y() >= 0 && Fl::event_y() < h()) {
        if (event == FL_PUSH) debug.append_line(mouse_event_to_string("Push").c_str());
        if (event == FL_DRAG) debug.append_line(mouse_event_to_string("Drag").c_str());
        if (event == FL_RELEASE) debug.append_line(mouse_event_to_string("Release").c_str());
        if (event == FL_MOVE) debug.append_line(mouse_event_to_string("Move").c_str());
        if (event == FL_MOUSEWHEEL) debug.append_line(mouse_event_to_string("MouseWheel").c_str());
      }
      return Fl_Window::handle(event);
    }
    
    void hide() override {
      Fl_Window::hide();
      exit(0);
    }
    
  private:
    static string mouse_event_to_string(const std::string& event_name) {
      return event_name + mouse_to_string();
    }
    
    static string mouse_to_string() {
      return "{button=" + mouse_button_to_string() + ", click_count = " + to_string(Fl::event_clicks()) + ", vertical_wheel_delta = " + to_string(Fl::event_dy()) + ", horizontal_wheel_delta = " + to_string(Fl::event_dx()) + ", location = [" + to_string(Fl::event_x()) + ", " + to_string(Fl::event_y()) + "], modifiers=" + modifiers_to_string() + "}";
    }
    
    static string mouse_button_to_string() {
      switch (Fl::event_button()) {
        case FL_LEFT_MOUSE: return "left";
        case FL_RIGHT_MOUSE: return "right";
        case FL_MIDDLE_MOUSE: return "middle";
        default: return "(unknown button)";
      }
    }
    
    static string modifiers_to_string() {
      string result;
      if (Fl::event_shift()) result += "shift, ";
      if (Fl::event_ctrl()) result += "control, ";
      if (Fl::event_alt()) result += "alt, ";
      if (Fl::event_command()) result += "command, ";
      if (result.size()) result.resize(result.size() - 2);
      else result = "none";
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
