#pragma once

enum class Fl_Scheme_Mode {
  default_mode,
  light,
  dark,
};

void fl_scheme_mode(Fl_Scheme_Mode scheme_mode);
Fl_Scheme_Mode fl_scheme_mode();
