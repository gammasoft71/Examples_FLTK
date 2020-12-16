#include <FL/Fl.H>
#include <FL/Fl_Clock.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Clock example") {
      clock1.box(Fl_Boxtype::FL_FLAT_BOX);
    }
    
  private:
    int handle(int event) override {
      if (event == FL_RELEASE) clock1.type(clock1.type() ==  FL_SQUARE_CLOCK ?  FL_ROUND_CLOCK :  FL_SQUARE_CLOCK);
      return Fl_Window::handle(event);
    }
    
    Fl_Clock clock1 {10, 10, 280, 280};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
