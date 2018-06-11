#include <FL/Fl.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Window.H>

class Fl_ProgressBar : public Fl_Progress {
public:
  Fl_ProgressBar(int x, int y, int w, int h) : Fl_Progress(x, y, w, h) {}
  
  void marquee(bool m) {
    this->m = m;
    if (this->m) Fl::add_timeout(0.2, OnMarqueeTimerTick, this);
  }
  bool marquee() const {return this->m;}
  
  void draw() override {
    this->Fl_Progress::draw();
    if (this->marquee()) {
      draw_box(FL_FLAT_BOX, this->x()+2, this->y() + 2, this->w() - 4, this->h() - 4, this->color());
      draw_box(FL_FLAT_BOX, this->x()+2 + marquee_pos, this->y() + 2, (this->w() - 4) / 10, this->h() - 4, this->selection_color());
    }
  }
  
private:
  static void OnMarqueeTimerTick(void* progress) {
    ((Fl_ProgressBar*)progress)->marquee_pos = ((Fl_ProgressBar*)progress)->marquee_pos < (((Fl_ProgressBar*)progress)->w() - ((((Fl_ProgressBar*)progress)->w() - 4) / 10)) ? ((Fl_ProgressBar*)progress)->marquee_pos + ((((Fl_ProgressBar*)progress)->w() - 4) / 10) : 0;
    ((Fl_ProgressBar*)progress)->redraw();
    if (((Fl_ProgressBar*)progress)->marquee()) Fl::repeat_timeout(0.2, OnMarqueeTimerTick, progress);
  }
  
  bool m= false;
  int marquee_pos = 0;
};

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
  
  Fl_ProgressBar progressBar1 {50, 50, 200, 25};
  Fl_ProgressBar progressBar2 {50, 80, 200, 25};
  Fl_ProgressBar progressBar3 {50, 110, 200, 25};
  Fl_ProgressBar progressBar4 {50, 140, 200, 25};
  Fl_ProgressBar progressBar5 {50, 170, 200, 25};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
