#include "Fl_Application.h"
#include <FL/Fl_Button.H>
#include <FL/fl_message.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Application and exception example"} {
      // uncomment to throw error
      //throw overflow_error {"Creation object error"};
      
      generate_handled_exception_button.callback(Main_Window::generate_handled_exception, this);
      
      generate_exception_button.callback(Main_Window::generate_exception, this);
      
      generate_unknown_exception_button.callback(Main_Window::generate_unknown_exception, this);
    }
    
  private:
    static void generate_handled_exception(Fl_Widget* sender, void* window) {
      try {
        throw invalid_argument {"Exception handled generated."};
      } catch (const exception& e) {
        fl_message_title("Exception handled");
        fl_message("%s", e.what());
      }
    }
    static void generate_exception(Fl_Widget* sender, void* window) {throw invalid_argument {"Exception generated"};}
    static void generate_unknown_exception(Fl_Widget* sender, void* window) {throw "Unknown exception generated";}

    Fl_Button generate_handled_exception_button {10, 10, 220, 25, "Generate handled exception"};
    Fl_Button generate_exception_button {10, 40, 220, 25, "Generate exception"};
    Fl_Button generate_unknown_exception_button {10, 70, 220, 25, "Generate unknown exception"};
  };
}

auto main(int argc, char *argv[]) -> int {
  try {
    Fl_Application::run(argc, argv, Examples::Main_Window {});
  } catch(const exception& e) {
    Fl_Application::show_exception_error("Exception occured", e);
  } catch(...) {
    Fl_Application::show_exception_error("Unknown exception occured");
  }
}
