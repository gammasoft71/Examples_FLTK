#include "Fl_Check_Box.H"
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "CheckBox example") {
    this->resizable(this);
    
    this->checkBox1.autocheck(false);
    this->checkBox1.state(FL_UNCHECKED);
    this->checkBox1.callback([](Fl_Widget* sender, void* form) {
      //((Fl_Check_Box*)sender)->state(!((Fl_Check_Box*)sender)->state());
      ((Fl_Check_Box*)sender)->label(state_to_string(((Fl_Check_Box*)sender)->state()));
    }, this);

    this->checkBox2.state(FL_CHECKED);
    this->checkBox2.callback([](Fl_Widget* sender, void* form) {
      ((Fl_Check_Box*)sender)->label(state_to_string(((Fl_Check_Box*)sender)->state()));
    }, this);

    this->checkBox3.three_state(true);
    this->checkBox3.state(FL_INDETERMINATE);
    this->checkBox3.callback([](Fl_Widget* sender, void* form) {
      ((Fl_Check_Box*)sender)->label(state_to_string(((Fl_Check_Box*)sender)->state()));
    }, this);

    this->checkBox4.state(FL_CHECKED);
    this->checkBox4.toggle_button(true);
    this->checkBox4.callback([](Fl_Widget* sender, void* form) {
      ((Fl_Check_Box*)sender)->label(state_to_string(((Fl_Check_Box*)sender)->state()));
    }, this);

    this->checkBox5.autocheck(false);
    this->checkBox5.state(FL_UNCHECKED);
    this->checkBox5.toggle_button(true);
    this->checkBox5.callback([](Fl_Widget* sender, void* form) {
      //((Fl_Check_Box*)sender)->state(!((Fl_Check_Box*)sender)->state());
      ((Fl_Check_Box*)sender)->label(state_to_string(((Fl_Check_Box*)sender)->state()));
    }, this);
  }
  
private:
  Fl_Check_Box checkBox1 {30, 30, 110, 23, "Unchecked"};
  Fl_Check_Box checkBox2 {30, 60, 110, 23, "Checked"};
  Fl_Check_Box checkBox3 {30, 90, 110, 23, "Indeterminate"};
  Fl_Check_Box checkBox4 {30, 120, 110, 23, "Checked"};
  Fl_Check_Box checkBox5 {30, 150, 110, 23, "Unchecked"};
  
  static const char* state_to_string(int state) {
    switch (state) {
      case FL_UNCHECKED: return "Unchecked";
      case FL_CHECKED: return "Checked";
      case FL_INDETERMINATE: return "Indeterminate";
      default: return "Undefined";
    }
  }
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
