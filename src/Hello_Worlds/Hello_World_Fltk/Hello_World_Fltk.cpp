#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(340, 180) {
      box1.box(FL_UP_BOX);
      box1.labelfont(FL_BOLD + FL_ITALIC);
      box1.labelsize(36);
      box1.labeltype(FL_SHADOW_LABEL);
    }
    
  private:
    Fl_Box box1 {20, 40, 300, 100, "Hello, World!"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
