#include "Fl_Scheme_Mode.h"
#include <optional>
#include <FL/Fl.H>

using namespace std;

namespace {
  optional<Fl_Color> original_background_color_;
  optional<Fl_Color> original_background2_color_;
  optional<Fl_Color> original_foreground_color_;
  optional<Fl_Color> original_selection_color_;
  Fl_Scheme_Mode scheme_mode_ = Fl_Scheme_Mode::default_mode;
  
  void init_original_colors() {
    if (!original_background_color_.has_value()) original_background_color_ = Fl::get_color(FL_BACKGROUND_COLOR);
    if (!original_background2_color_.has_value()) original_background2_color_ = Fl::get_color(FL_BACKGROUND2_COLOR);
    if (!original_foreground_color_.has_value()) original_foreground_color_ = Fl::get_color(FL_FOREGROUND_COLOR);
    if (!original_selection_color_.has_value()) original_selection_color_ = Fl::get_color(FL_SELECTION_COLOR);
  }
  
  void set_scheme_light_mode() {
    init_original_colors();
#if _WIN32
    Fl::background(240, 240, 240);
    Fl::background2(255, 255, 255);
    Fl::foreground(0, 0, 0);
    Fl::set_color(FL_SELECTION_COLOR, 0, 120, 215);
#elif __APPLE__
    Fl::background(236, 236, 236);
    Fl::background2(255, 255, 255);
    Fl::foreground(0 ,0, 0);
    Fl::set_color(FL_SELECTION_COLOR, 0, 98, 225);
#else
    Fl::background(241, 240, 238);
    Fl::background2(255, 255, 255);
    Fl::foreground(0, 0, 0);
    Fl::set_color(FL_SELECTION_COLOR, 53, 100, 228);
#endif
    Fl::redraw();
  }
  
  void set_scheme_dark_mode() {
    init_original_colors();
#if _WIN32
    Fl::background(25, 25, 25);
    Fl::background2(32, 32, 32);
    Fl::foreground(255, 255, 255);
    Fl::set_color(FL_SELECTION_COLOR, 0, 160, 250);
#elif __APPLE__
    Fl::background(50, 50, 50);
    Fl::background2(23, 23, 23);
    Fl::foreground(223, 223, 223);
    Fl::set_color(FL_SELECTION_COLOR, 0, 87, 207);
#else
    Fl::background(51, 51, 51);
    Fl::background2(45, 45, 45);
    Fl::foreground(255, 255, 255);
    Fl::set_color(FL_SELECTION_COLOR, 21, 83, 158);
#endif
    Fl::redraw();
  }
  
  void set_scheme_default_mode() {
    init_original_colors();
    set_scheme_light_mode(); // Workaround : When the previous scheme_mode is dark, the refresh was not clean...
    Fl::set_color(FL_BACKGROUND_COLOR, original_background_color_.value());
    Fl::set_color(FL_BACKGROUND2_COLOR, original_background2_color_.value());
    Fl::set_color(FL_FOREGROUND_COLOR, original_foreground_color_.value());
    Fl::set_color(FL_SELECTION_COLOR, original_selection_color_.value());
    Fl::redraw();
  }
}

void fl_scheme_mode(Fl_Scheme_Mode scheme_mode) {
  if (scheme_mode_ != scheme_mode) {
    scheme_mode_ = scheme_mode;
    if (scheme_mode_ == Fl_Scheme_Mode::default_mode) set_scheme_default_mode();
    else if (scheme_mode_ == Fl_Scheme_Mode::dark) set_scheme_dark_mode();
    else if (scheme_mode_ == Fl_Scheme_Mode::light) set_scheme_light_mode();
  }
}

Fl_Scheme_Mode fl_scheme_mode() {
  return scheme_mode_;
}

