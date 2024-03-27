#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 640, 480, "Window example"} {
      button.align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->hide();
      }, this);
    }

    void hide() override {
      fl_message_hotspot(false);
      fl_message_title("Close window");
      if (fl_choice("Are you sure you want exit?", "No", "Yes", nullptr) == 1) Fl_Window::hide();
    }
    
  private:
    Fl_Button button {10, 10, 75, 25, "Close"};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
