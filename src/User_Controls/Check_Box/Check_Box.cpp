#include "Fl_Check_Box.h"
#include <map>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Check box example") {
      end();
      resizable(this);
      
      check_box1.auto_check(false);
      check_box1.state(FL_UNCHECKED);
      check_box1.callback([](Fl_Widget* sender, void* window) {
        //reinterpret_cast<Fl_Check_Box*>(sender)->state(!reinterpret_cast<Fl_Check_Box*>(sender)->state());
        reinterpret_cast<Fl_Check_Box*>(sender)->label(state_to_string(reinterpret_cast<Fl_Check_Box*>(sender)->state()));
      }, this);

      check_box2.state(FL_CHECKED);
      check_box2.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Check_Box*>(sender)->label(state_to_string(reinterpret_cast<Fl_Check_Box*>(sender)->state()));
      }, this);

      check_box3.three_state(true);
      check_box3.state(FL_INDETERMINATE);
      check_box3.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Check_Box*>(sender)->label(state_to_string(reinterpret_cast<Fl_Check_Box*>(sender)->state()));
      }, this);

      check_box4.state(FL_CHECKED);
      check_box4.toggle_button(true);
      check_box4.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Check_Box*>(sender)->label(state_to_string(reinterpret_cast<Fl_Check_Box*>(sender)->state()));
      }, this);

      check_box5.auto_check(false);
      check_box5.state(FL_UNCHECKED);
      check_box5.toggle_button(true);
      check_box5.callback([](Fl_Widget* sender, void* window) {
        //reinterpret_cast<Fl_Check_Box*>(sender)->state(!reinterpret_cast<Fl_Check_Box*>(sender)->state());
        reinterpret_cast<Fl_Check_Box*>(sender)->label(state_to_string(reinterpret_cast<Fl_Check_Box*>(sender)->state()));
      }, this);
    }
    
  private:
    Fl_Check_Box check_box1 {30, 30, 110, 23, "Unchecked"};
    Fl_Check_Box check_box2 {30, 60, 110, 23, "Checked"};
    Fl_Check_Box check_box3 {30, 90, 110, 23, "Indeterminate"};
    Fl_Check_Box check_box4 {30, 120, 110, 23, "Checked"};
    Fl_Check_Box check_box5 {30, 150, 110, 23, "Unchecked"};
    
    static const char* state_to_string(int state) {
      static map<int, const char*> states = {{FL_UNCHECKED, "Unchecked"}, {FL_CHECKED, "Checked"}, {FL_INDETERMINATE, "Indeterminate"}};
      return states[state];
    }
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
