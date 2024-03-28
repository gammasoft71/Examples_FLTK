#include <FL/Fl.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Click anywhere on the window") {}
    
    auto handle(int event) -> int override {
      if (event == FL_RELEASE && Fl::event_button() == FL_LEFT_MOUSE) {
        fl_message_hotspot(false);
        fl_message_title("Main_Window_Click");
        fl_message("The window is clicked at {x=%d, y=%d}", Fl::event_x(), Fl::event_y());
      }
      return Fl_Window::handle(event);
    }
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
