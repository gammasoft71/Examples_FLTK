#include "Fl_Check_Box.H"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "CheckBox example") {
    this->resizable(this);
    
    this->checkBox1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->checkBox1.value(1);
    
    this->checkBox2.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->checkBox2.value(0);

    this->checkBox3.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->checkBox3.indeterminate(true);
    this->checkBox3.callback([](Fl_Widget* sender, void* form) {
      ((Fl_Check_Box*)sender)->indeterminate(false);
      ((Fl_Check_Box*)sender)->redraw();
    }, this);
  }
  
private:
  Fl_Check_Box checkBox1 {30, 30, 110, 23, "Checked"};
  Fl_Check_Box checkBox2 {30, 60, 110, 23, "Unchecked"};
  Fl_Check_Box checkBox3 {30, 90, 110, 23, "Indeterminate"};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
