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
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::run();
}
