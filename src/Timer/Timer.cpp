#include <iomanip>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 230, 130, "Timer example") {
    this->resizable(this);
    
    this->button.callback([](Fl_Widget* sender, void* form) {
      ((Form*)form)->enableTimer = !((Form*)form)->enableTimer;
      ((Form*)form)->button.copy_label(((Form*)form)->enableTimer ? "Stop" : "Start");
      if (((Form*)form)->enableTimer) Fl::add_timeout(0.1, OnTimerTick, form);
    }, this);
    
    this->label.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->label.labelfont(FL_HELVETICA_BOLD_ITALIC);
    this->label.labelsize(64);
    this->label.labelcolor(fl_rgb_color(30, 144, 255));
  }
  
private:
  static void OnTimerTick(void* form) {
    stringstream stream;
    stream << fixed << setprecision(1) << (double)++((Form*)form)->timer / 10;
    ((Form*)form)->label.copy_label(stream.str().c_str());
    if (((Form*)form)->enableTimer) Fl::repeat_timeout(0.1, OnTimerTick, form);
  }

  Fl_Box label {10, 10, 210, 70, "0.0"};
  Fl_Button button {10, 90, 75, 25, "Start"};
  bool enableTimer = false;
  int timer = 0;
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
