#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 640, 480, "Scroll example") {
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

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
