#include "Fl_Scheme_Mode.h"
#include <functional>
#include <map>
#include <optional>
#include <FL/Fl.H>

using namespace std;

namespace {
  auto original_background_color_ = optional<Fl_Color> {};
  auto original_background2_color_ = optional<Fl_Color> {};
  auto original_foreground_color_ = optional<Fl_Color> {};
  auto original_selection_color_ = optional<Fl_Color> {};
  auto scheme_mode_ = Fl_Scheme_Mode::default_mode;
  
  void init_original_colors() {
    if (!original_background_color_.has_value()) original_background_color_ = Fl::get_color(FL_BACKGROUND_COLOR);
    if (!original_background2_color_.has_value()) original_background2_color_ = Fl::get_color(FL_BACKGROUND2_COLOR);
    if (!original_foreground_color_.has_value()) original_foreground_color_ = Fl::get_color(FL_FOREGROUND_COLOR);
    if (!original_selection_color_.has_value()) original_selection_color_ = Fl::get_color(FL_SELECTION_COLOR);
  }
  
  void set_scheme_light_mode() {
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
  }
  
  void set_scheme_dark_mode() {
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
  }
 
  void set_scheme_default_mode() {
    unsigned char r = 0, g = 0, b = 0;
    Fl::get_color(original_background_color_.value(), r, g, b);
    Fl::background(r, g, b);
    Fl::set_color(FL_BACKGROUND2_COLOR, original_background2_color_.value());
    Fl::set_color(FL_FOREGROUND_COLOR, original_foreground_color_.value());
    Fl::set_color(FL_SELECTION_COLOR, original_selection_color_.value());
  }
  
  void set_scheme_white_mode() {
    Fl::background(248, 248, 255);
    Fl::background2(255, 255, 255);
    Fl::foreground(80, 80, 80);
#if _WIN32
    Fl::set_color(FL_SELECTION_COLOR, 0, 120, 215);
#elif __APPLE__
    Fl::set_color(FL_SELECTION_COLOR, 0, 98, 225);
#else
    Fl::set_color(FL_SELECTION_COLOR, 53, 100, 228);
#endif
  }
  
  void set_scheme_black_mode() {
    Fl::background(16, 16, 16);
    Fl::background2(0, 0, 0);
    Fl::foreground(120, 120, 120);
#if _WIN32
    Fl::set_color(FL_SELECTION_COLOR, 0, 160, 250);
#elif __APPLE__
    Fl::set_color(FL_SELECTION_COLOR, 0, 87, 207);
#else
    Fl::set_color(FL_SELECTION_COLOR, 21, 83, 158);
#endif
  }

  void set_scheme_red_mode() {
    Fl::background(36, 0, 0);
    Fl::background2(8, 0, 0);
    Fl::foreground(223, 100, 100);
    Fl::set_color(FL_SELECTION_COLOR, 220, 50, 50);
  }
  
  void set_scheme_green_mode() {
    Fl::background(0, 36, 0);
    Fl::background2(0, 8, 0);
    Fl::foreground(100, 223, 100);
    Fl::set_color(FL_SELECTION_COLOR, 50, 220, 50);
  }
  
  void set_scheme_blue_mode() {
    Fl::background(0, 0, 64);
    Fl::background2(0, 0, 16);
    Fl::foreground(90, 90, 255);
    Fl::set_color(FL_SELECTION_COLOR, 80, 80, 255);
  }
}

void fl_scheme_mode(Fl_Scheme_Mode scheme_mode) {
  init_original_colors();
  static auto set_modes = map<Fl_Scheme_Mode, std::function<void()>> {{Fl_Scheme_Mode::default_mode, set_scheme_default_mode}, {Fl_Scheme_Mode::dark, set_scheme_dark_mode}, {Fl_Scheme_Mode::light, set_scheme_light_mode}, {Fl_Scheme_Mode::white, set_scheme_white_mode}, {Fl_Scheme_Mode::black, set_scheme_black_mode}, {Fl_Scheme_Mode::red, set_scheme_red_mode}, {Fl_Scheme_Mode::green, set_scheme_green_mode}, {Fl_Scheme_Mode::blue, set_scheme_blue_mode}};
  if (scheme_mode_ != scheme_mode) {
    scheme_mode_ = scheme_mode;
    set_modes[scheme_mode_]();
  }
}

Fl_Scheme_Mode fl_scheme_mode() {
  init_original_colors();
  return scheme_mode_;
}

