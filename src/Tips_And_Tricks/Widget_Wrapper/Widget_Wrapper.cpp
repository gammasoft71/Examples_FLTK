#include "Fl_Widget_Wrapper.h"
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Widget wrapper example") {
      button.callback([&](Fl_Widget& sender, std::any arg) {
        fl_message("Clicked %d times", ++count);
      });
    }
    
  private:
    Fl_Widget_Wrapper<Fl_Button> button {10, 10, 75, 25, "Click me"};
    int count = 0;
  };
}

int main(int argc, char* argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::run();
}
