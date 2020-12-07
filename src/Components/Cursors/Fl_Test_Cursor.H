#pragma once
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Scroll.H>

using namespace std;

class Fl_Test_Cursor : public Fl_Scroll {
public:
  Fl_Test_Cursor(int x, int y, int w ,int h) : Fl_Scroll(x, y, w, h) {}

  void cursor(Fl_Cursor cursor) {c = cursor;}

  int handle(int event) override {
    if (event == FL_ENTER) fl_cursor(c);
    if (event == FL_LEAVE) fl_cursor(FL_CURSOR_DEFAULT);
    return Fl_Scroll::handle(event);
  }
  
private:
  Fl_Cursor c = FL_CURSOR_DEFAULT;
};
