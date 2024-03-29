#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Check_Button.H>

static constexpr int FL_UNCHECKED = 0;
static constexpr int FL_CHECKED = 1;
static constexpr int FL_INDETERMINATE = 2;

class Fl_Check_Box : public Fl_Check_Button {
public:
  Fl_Check_Box(int x, int y, int w, int h, const char* l = 0) : Fl_Check_Button {x, y, w, h, l} {toggle_button(false);}
  
  bool auto_check() const noexcept {return auto_check_;}
  void auto_check(bool auto_check) noexcept {auto_check_ = auto_check;}
  
  bool three_state() const noexcept {return three_state_;}
  void three_state(bool three_state) noexcept {three_state_ = three_state;}
  
  bool toggle_button() const noexcept {return toggle_button_;}
  void toggle_button(bool toggle_button) noexcept {
    toggle_button_ = toggle_button;
    if (toggle_button_) {
      box(FL_UP_BOX);
      down_box(FL_NO_BOX);
      color(FL_BACKGROUND_COLOR);
      selection_color(FL_BACKGROUND_COLOR);
      align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    } else {
      color(FL_BACKGROUND_COLOR);
      selection_color(FL_FOREGROUND_COLOR);
      align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
  }

  int state() const noexcept {return state_;}
  void state(int state) noexcept {
    if (state_ != state) {
      state_ = state > 2 ? 2 : state;
      value(state != 0);
      set_changed();
      if (when() & FL_WHEN_CHANGED) do_callback();
    }
  }

  auto handle (int event) noexcept -> int override {
    if (event == FL_PUSH || event == FL_DRAG) return true;
    if (event == FL_RELEASE || (event == FL_KEYBOARD && Fl::focus() == this && Fl::event_key() == ' ' && !(Fl::event_state() & (FL_SHIFT | FL_CTRL | FL_ALT | FL_META)))) {
      if (auto_check_) {
        state(state() < (three_state() ? FL_INDETERMINATE : FL_CHECKED) ? state() + 1 : 0);
        redraw();
      }
      if (when() & FL_WHEN_RELEASE) do_callback();
      return true;
    }
    return Fl_Check_Button::handle(event);
  }
  
  void draw() override {
    if (toggle_button() == true)
      Fl_Button::draw();
    else {
      Fl_Check_Button::draw();
      if (state() == FL_INDETERMINATE && toggle_button() == false)
        draw_box(FL_FLAT_BOX, x() + 5, y() + (h() - 14) / 2 + 3, 8, 8, selection_color());
    }
  }
  
private:
  using Fl_Check_Button::value;
  bool auto_check_ = true;
  bool toggle_button_ = false;
  int state_ = FL_UNCHECKED;
  bool three_state_ = false;
};
