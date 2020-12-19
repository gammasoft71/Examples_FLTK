#pragma once

bool fl_use_wait_cursor();
void fl_use_wait_cursor(bool use_wait_cursor);

class Fl_Use_Wait_Cursor {
public:
  Fl_Use_Wait_Cursor() {fl_use_wait_cursor(true);}
  ~Fl_Use_Wait_Cursor() {fl_use_wait_cursor(false);}
};
