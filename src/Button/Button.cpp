#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "Label example") {
    this->resizable(this);
    
    this->button1.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->button1.callback([](Fl_Widget* sender, void* form) {
      std::string result = "button1 clicked " + std::to_string(++((Form*)form)->button1Clicked) + " times";
      ((Form*)form)->label1.copy_label(result.c_str());
    }, this);
    
    this->button2.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->button2.callback([](Fl_Widget* sender, void* form) {
      std::string result = "button2 clicked " + std::to_string(++((Form*)form)->button2Clicked) + " times";
      ((Form*)form)->label2.copy_label(result.c_str());
    }, this);

    this->label1.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->label2.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  }
  
private:
  Fl_Button button1 {50, 50, 75, 25, "button1"};
  Fl_Button button2 {50, 100, 200, 75, "button2"};
  Fl_Box label1 {50, 200, 200, 20, "button1 clicked 0 times"};
  Fl_Box label2 {50, 230, 200, 25, "button2 clicked 0 times"};
  int button1Clicked = 0;
  int button2Clicked = 0;
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
