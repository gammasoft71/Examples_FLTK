#include "Fl_Application.h"
#include <FL/Fl_Button.H>

using namespace std;

namespace Examples {
  class Main_Window final : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Application and exception example") {
      resizable(this);
      
      generate_handled_exception_button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      generate_handled_exception_button.callback(Main_Window::generate_handled_exception, this);
      
      generate_exception_button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      generate_exception_button.callback(Main_Window::generate_exception, this);
      
      generate_unknown_exception_button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      generate_unknown_exception_button.callback(Main_Window::generate_unknown_exception, this);
    }
    
  private:
    static void generate_handled_exception(Fl_Widget* sender, void* window) {
      try {
        throw invalid_argument("Exception handled generated");
      } catch (const exception& e) {
        fl_message_icon()->label("i");
        fl_message_icon()->color(fl_rgb_color(0, 0, 255));
        fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
        fl_message_title("Exception handled");
        fl_message_hotspot(false);
        fl_message("%s", e.what());
      }
    }
    static void generate_exception(Fl_Widget* sender, void* window) {throw invalid_argument("Exception generated");}
    static void generate_unknown_exception(Fl_Widget* sender, void* window) {throw "Unknown exception generated";}

    Fl_Button generate_handled_exception_button {10, 10, 200, 25, "Generate handled exception"};
    Fl_Button generate_exception_button {10, 40, 150, 25, "Generate exception"};
    Fl_Button generate_unknown_exception_button {10, 70, 200, 25, "Generate unknown exception"};
  };
}

int main(int argc, char *argv[]) {
  Fl_Application::run(argc, argv, Examples::Main_Window());
}
