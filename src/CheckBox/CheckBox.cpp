#include <FL/Fl.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Window.H>

class Fl_CheckBox : public Fl_Check_Button {
public:
  Fl_CheckBox(int x, int y, int w, int h, const char* l = 0) : Fl_Check_Button(x, y, w, h, l) {}
  
  void indeterminate(bool i) {this->i = i;}
  bool indeterminate() const {return this->i;}
  
  void draw() override {
    this->Fl_Check_Button::draw();
    if (this->i) draw_box(FL_FLAT_BOX, this->x() + 5, this->y() + (this->h() - 14) / 2 + 3, 8, 8, FL_FOREGROUND_COLOR);
  }
  
private:
  bool i = false;
};

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
  }
  
private:
  Fl_CheckBox checkBox1 {30, 30, 110, 23, "Checked"};
  Fl_CheckBox checkBox2 {30, 60, 110, 23, "Unchecked"};
  Fl_CheckBox checkBox3 {30, 90, 110, 23, "Indeterminate"};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
