#include <FL/Fl.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "RadioButton example") {
    this->resizable(this);
    
    this->radioButton1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->radioButton1.value(1);
    
    this->radioButton2.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);

    this->radioButton3.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  }
  
private:
  Fl_Radio_Round_Button radioButton1 {30, 30, 110, 23, "radioButton 1"};
  Fl_Radio_Round_Button radioButton2 {30, 60, 110, 23, "radioButton 2"};
  Fl_Radio_Round_Button radioButton3 {30, 90, 110, 23, "radioButton 3"};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
