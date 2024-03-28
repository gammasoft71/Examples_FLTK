#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Tooltip example") {
      box.align(FL_ALIGN_LEFT | FL_ALIGN_CLIP | FL_ALIGN_INSIDE);
    }
    
    auto handle(int event) -> int override {
      if (event == FL_MOVE) {
        if (Fl::belowmouse() == &button) {
          Fl_Tooltip::enter_area(&button, 10, 10, 75, 25, "Button tooltip...");
        } else if (Fl::belowmouse() == &check_button) {
          Fl_Tooltip::enter_area(&check_button, 10, 40, 100, 25, "Check button tooltip...");
        } else if (Fl::belowmouse() == &box) {
          Fl_Tooltip::enter_area(&box, 10, 70, 50, 25, "Box tooltip...");
        } else {
          Fl_Tooltip::current(nullptr);
        }
      }
      return Fl_Window::handle(event);
    }

  private:
    Fl_Button button {10, 10, 75, 25, "button"};
    Fl_Check_Button check_button {10, 40, 100, 25, "check"};
    Fl_Box box {10, 70, 50, 25, "box"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
