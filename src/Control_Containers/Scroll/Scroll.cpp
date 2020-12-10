#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 640, 480, "Scroll example") {
      scroll1 = make_unique<Fl_Scroll>(10, 10, 305, 460);
      scroll1->box(FL_BORDER_BOX);
      scroll1->end();

      scroll2 = make_unique<Fl_Scroll>(325, 10, 305, 460);
      scroll2->box(FL_DOWN_BOX);
      scroll2->end();

      end();
      resizable(this);
    }
    
  private:
    unique_ptr<Fl_Scroll> scroll1;
    unique_ptr<Fl_Scroll> scroll2;
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
