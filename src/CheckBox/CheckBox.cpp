#include "Fl_Check_Box.H"
#include <map>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Window : public Fl_Window {
  public:
    Window() : Fl_Window(200, 100, 300, 300, "CheckBox example") {
      resizable(this);
      
      checkBox1.autocheck(false);
      checkBox1.state(FL_UNCHECKED);
      checkBox1.callback([](Fl_Widget* sender, void* window) {
        //reinterpret_cast<Fl_Check_Box*>(sender)->state(!reinterpret_cast<Fl_Check_Box*>(sender)->state());
        reinterpret_cast<Fl_Check_Box*>(sender)->label(state_to_string(reinterpret_cast<Fl_Check_Box*>(sender)->state()));
      }, this);

      checkBox2.state(FL_CHECKED);
      checkBox2.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Check_Box*>(sender)->label(state_to_string(reinterpret_cast<Fl_Check_Box*>(sender)->state()));
      }, this);

      checkBox3.three_state(true);
      checkBox3.state(FL_INDETERMINATE);
      checkBox3.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Check_Box*>(sender)->label(state_to_string(reinterpret_cast<Fl_Check_Box*>(sender)->state()));
      }, this);

      checkBox4.state(FL_CHECKED);
      checkBox4.toggle_button(true);
      checkBox4.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Check_Box*>(sender)->label(state_to_string(reinterpret_cast<Fl_Check_Box*>(sender)->state()));
      }, this);

      checkBox5.autocheck(false);
      checkBox5.state(FL_UNCHECKED);
      checkBox5.toggle_button(true);
      checkBox5.callback([](Fl_Widget* sender, void* window) {
        //reinterpret_cast<Fl_Check_Box*>(sender)->state(!reinterpret_cast<Fl_Check_Box*>(sender)->state());
        reinterpret_cast<Fl_Check_Box*>(sender)->label(state_to_string(reinterpret_cast<Fl_Check_Box*>(sender)->state()));
      }, this);
    }
    
  private:
    Fl_Check_Box checkBox1 {30, 30, 110, 23, "Unchecked"};
    Fl_Check_Box checkBox2 {30, 60, 110, 23, "Checked"};
    Fl_Check_Box checkBox3 {30, 90, 110, 23, "Indeterminate"};
    Fl_Check_Box checkBox4 {30, 120, 110, 23, "Checked"};
    Fl_Check_Box checkBox5 {30, 150, 110, 23, "Unchecked"};
    
    static const char* state_to_string(int state) {
      static map<int, const char*> states = {{FL_UNCHECKED, "Unchecked"}, {FL_CHECKED, "Checked"}, {FL_INDETERMINATE, "Indeterminate"}};
      return states[state];
    }
  };
}

int main(int argc, char *argv[]) {
  Examples::Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
