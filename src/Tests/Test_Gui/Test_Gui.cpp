#include <FL/Fl.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Test gui") {
      
    }
  };
}

int main(int argc, char* argv[]) {
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::run();
}
