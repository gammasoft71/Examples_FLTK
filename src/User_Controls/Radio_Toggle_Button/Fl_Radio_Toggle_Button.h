#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Radio_Round_Button.H>

static constexpr int FL_UNCHECKED = 0;
static constexpr int FL_CHECKED = 1;

class Fl_Radio_Toggle_Button : public Fl_Radio_Round_Button {
public:
  Fl_Radio_Toggle_Button(int x, int y, int w, int h, const char* l = 0) : Fl_Radio_Round_Button {x, y, w, h, l} {toggle_button(false);}
  
  bool auto_check() const {return auto_check_;}
  void auto_check(bool auto_check) {auto_check_ = auto_check;}
  
  bool toggle_button() const {return toggle_button_;}
  void toggle_button(bool toggle_button) {
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

  int state() const {return state_;}
  void state(int state) {
    if (state_ !=  state) {
      state_ = state > 2 ? 2 : state;
      value(state != 0);
      set_changed();
      if (when() & FL_WHEN_CHANGED) do_callback();
    }
  }

  int handle (int event) override {
    if (event == FL_PUSH || event == FL_DRAG) return true;
    if (event == FL_RELEASE || (event == FL_KEYBOARD && Fl::focus() == this && Fl::event_key() == ' ' && !(Fl::event_state() & (FL_SHIFT | FL_CTRL | FL_ALT | FL_META)))) {
      if (auto_check_) {
        state(FL_CHECKED);
        if (parent()) {
          for ( int index = 0; index < parent()->children(); index++) {
            if (parent()->child(index) != this && dynamic_cast<Fl_Radio_Toggle_Button*>(parent()->child(index)) && static_cast<Fl_Radio_Toggle_Button*>(parent()->child(index))->auto_check())
              static_cast<Fl_Radio_Toggle_Button*>(parent()->child(index))->state(FL_UNCHECKED);
          }
        }
        
        redraw();
      }
      if (when() & FL_WHEN_RELEASE) do_callback();
      return true;
    }
    return Fl_Radio_Round_Button::handle(event);
  }
  
  void draw() override {
    if (toggle_button() == true) Fl_Button::draw();
    else Fl_Radio_Round_Button::draw();
  }
  
private:
  using Fl_Radio_Round_Button::value;
  bool auto_check_ = true;
  bool toggle_button_ = false;
  int state_ = FL_UNCHECKED;
};
