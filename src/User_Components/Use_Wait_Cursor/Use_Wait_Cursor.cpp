#include "Fl_Use_Wait_Cursor.h"
#include <iostream>
#include <thread>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Use wait cursor example") {
      button1.callback([](Fl_Widget* sender, void* data) {
        fl_use_wait_cursor(true);
        cout << "use_wait_cursor = " << std::boolalpha << fl_use_wait_cursor() << endl;
        for (auto count = 0; count < 500; ++count) {
          Fl::wait(0);
          sleep_for(milliseconds(10)); // Simulate work...
        }
        fl_use_wait_cursor(false);
        cout << "use_wait_cursor = " << std::boolalpha << fl_use_wait_cursor() << endl;
      });

      button2.callback([](Fl_Widget* sender, void* data) {
        Fl_Use_Wait_Cursor wait_cursor;
        for (auto count = 0; count < 500; ++count) {
          Fl::wait(0);
          sleep_for(milliseconds(10)); // Simulate work...
        }
      });
    }
    
  private:
    Fl_Button button1 {10, 10, 120, 25, "Do something..."};
    Fl_Button button2 {10, 50, 120, 25, "Do other thing..."};
  };
}

int main(int argc, char* argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::run();
}
