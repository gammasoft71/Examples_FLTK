#include "fl_functional.h"
#include <functional>
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::placeholders;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Functional example") {
      fl_functional(button1, bind(&Main_Window::on_click, this, _1, _2), *this);
      fl_functional(button2, bind(&Main_Window::on_click2, this, _1));
      fl_functional(button3, [&](Fl_Widget& sender) {
        cout << "clicked " << ++count << " times" << endl;
      });
    }
    
  private:
    void on_click(Fl_Widget& sender, Main_Window& data) {
      cout << "clicked " << ++count << " times" << endl;
    }
    
    void on_click2(Fl_Widget& sender) {
      cout << "clicked " << ++count << " times" << endl;
    }
    
    Fl_Repeat_Button button1 {10, 10, 75, 25, "button1"};
    Fl_Repeat_Button button2 {10, 50, 75, 25, "button2"};
    Fl_Repeat_Button button3 {10, 90, 75, 25, "button3"};
    int count = 0;
  };
}

int main(int argc, char* argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::run();
}
