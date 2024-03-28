#include <FL/Fl.H>
#include <FL/Fl_Clock.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Clock output example"} {
      clock_output1.box(Fl_Boxtype::FL_FLAT_BOX);
      clock_output1.value(10, 10, 30);
    }
    
  private:
    auto handle(int event) -> int override {
      if (event == FL_RELEASE) {
        clock_output1.type(clock_output1.type() == FL_SQUARE_CLOCK ? FL_ROUND_CLOCK : FL_SQUARE_CLOCK);
        clock_output1.redraw();
      }
      return Fl_Window::handle(event);
    }
    
    Fl_Clock_Output clock_output1 {10, 10, 280, 280};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
