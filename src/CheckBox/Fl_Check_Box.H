#pragma once
#include <FL/Fl_Check_Button.H>

class Fl_Check_Box : public Fl_Check_Button {
public:
  Fl_Check_Box(int x, int y, int w, int h, const char* l = 0) : Fl_Check_Button(x, y, w, h, l) {}
  
  void indeterminate(bool i) {this->i = i;}
  bool indeterminate() const {return this->i;}
  
  void draw() override {
    this->Fl_Check_Button::draw();
    if (this->i) draw_box(FL_FLAT_BOX, this->x() + 5, this->y() + (this->h() - 14) / 2 + 3, 8, 8, FL_FOREGROUND_COLOR);
  }
  
private:
  bool i = false;
};
