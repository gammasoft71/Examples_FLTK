#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include "Fl_Progress_Bar.H"
#include <FL/Fl_Slider.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "TrackBar example") {
    this->resizable(this);
    
    this->trackBar.type(FL_VERT_NICE_SLIDER);
    this->trackBar.maximum(200);
    this->trackBar.callback([](Fl_Widget* sender, void* form) {
      ((Form*)form)->progressBar.value((float)((Form*)form)->trackBar.maximum() - (float)((Form*)form)->trackBar.value());
      ((Form*)form)->label.copy_label(to_string((int)(((Form*)form)->trackBar.maximum() - ((Form*)form)->trackBar.value())).c_str());
    }, this);
    this->trackBar.value(100);
    this->trackBar.do_callback();

    this->deactivate();
    this->progressBar.type(FL_VERT_PROGRESS_BAR);
    this->progressBar.maximum(200);

    this->label.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  }
  
private:
  Fl_Slider trackBar {20, 50, 25, 200};
  Fl_Progress_Bar progressBar {100, 50, 25, 200};
  Fl_Box label {150, 50, 75, 25};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
