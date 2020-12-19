#include "Fl_Use_Wait_Cursor.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

namespace {
  bool use_wait_cursor = false;
}

bool fl_use_wait_cursor() {
  return use_wait_cursor;
}

void fl_use_wait_cursor(bool use_wait_cursor) {
  if (::use_wait_cursor == use_wait_cursor) return;
  ::use_wait_cursor = use_wait_cursor;
  for (auto window = Fl::first_window(); window; window = Fl::next_window(window))
    window->cursor(use_wait_cursor ? FL_CURSOR_WAIT : FL_CURSOR_DEFAULT);
}
