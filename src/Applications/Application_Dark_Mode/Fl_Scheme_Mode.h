#pragma once

enum class Fl_Scheme_Mode {
  default_mode,
  light,
  dark,
  white,
  black,
  red,
  green,
  blue,
};

void fl_scheme_mode(Fl_Scheme_Mode scheme_mode);
Fl_Scheme_Mode fl_scheme_mode();
