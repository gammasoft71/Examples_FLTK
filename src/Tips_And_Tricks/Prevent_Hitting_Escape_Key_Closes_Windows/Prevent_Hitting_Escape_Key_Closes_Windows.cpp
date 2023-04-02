#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 800, 450, "Prevent hitting 'Escape' key closes windows") {}
  };
}

int main(int argc, char* argv[]) {
  // The following line prevent hitting the 'Escape' key closes windows...
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::run();
}
