#include "Fl_Progress_Bar.H"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "ProgressBar example") {
    this->resizable(this);
    
    this->progressBar2.value(50);
    
    this->progressBar3.value(100);
    
    this->progressBar4.maximum(140);
    Fl::add_timeout(0.05, OnTimerTick, this);
    
    this->progressBar5.marquee(true);
  }

private:
  static void OnTimerTick(void* form) {
    ((Form*)form)->progressBar4.value(((Form*)form)->progressBar4.value() < ((Form*)form)->progressBar4.maximum() ? ((Form*)form)->progressBar4.value() + 1 : ((Form*)form)->progressBar4.minimum());
    Fl::repeat_timeout(0.05, OnTimerTick, form);
  }
  
  Fl_Progress_Bar progressBar1 {50, 50, 200, 25};
  Fl_Progress_Bar progressBar2 {50, 80, 200, 25};
  Fl_Progress_Bar progressBar3 {50, 110, 200, 25};
  Fl_Progress_Bar progressBar4 {50, 140, 200, 25};
  Fl_Progress_Bar progressBar5 {50, 170, 200, 25};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
