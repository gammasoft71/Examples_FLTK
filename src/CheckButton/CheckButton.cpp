#include <FL/Fl_Check_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class MainWindow : public Fl_Window {
  public:
    MainWindow() : Fl_Window(200, 100, 300, 300, "CheckButton example") {
      resizable(this);
      
      checkButton1.value(false);
      checkButton1.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Check_Button*>(sender)->value(0);
      }, this);
      
      checkButton2.value(true);
      checkButton2.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Check_Button*>(sender)->label(reinterpret_cast<Fl_Check_Button*>(sender)->value() ? "Checked" : "Unchecked");
      }, this);      
    }
    
  private:
    Fl_Check_Button checkButton1 {30, 30, 110, 23, "Unchecked"};
    Fl_Check_Button checkButton2 {30, 60, 110, 23, "Checked"};
  };
}

int main(int argc, char *argv[]) {
  Examples::MainWindow window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
