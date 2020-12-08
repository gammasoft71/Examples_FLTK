#include <FL/Fl_Check_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "CheckButton example") {
      end();
      resizable(this);
      
      check_button1.value(false);
      check_button1.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Check_Button*>(sender)->value(0);
      }, this);
      
      check_button2.value(true);
      check_button2.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Check_Button*>(sender)->label(reinterpret_cast<Fl_Check_Button*>(sender)->value() ? "Checked" : "Unchecked");
      }, this);      
    }
    
  private:
    Fl_Check_Button check_button1 {30, 30, 110, 23, "Unchecked"};
    Fl_Check_Button check_button2 {30, 60, 110, 23, "Checked"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
