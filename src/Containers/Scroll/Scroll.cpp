#include <FL/Fl.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 640, 480, "Scroll example"} {
      scroll1.box(FL_BORDER_BOX);
      scroll2.box(FL_DOWN_BOX);
    }
    
  private:
    Fl_Scroll scroll1 {10, 10, 305, 460};
    Fl_End end_scroll1;
    Fl_Scroll scroll2 {325, 10, 305, 460};
    Fl_End end_scroll2;
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
