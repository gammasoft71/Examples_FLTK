#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Progress.H>

class Fl_Progress_Bar : public Fl_Progress {
public:
  Fl_Progress_Bar(int x, int y, int w, int h, const char* label = nullptr) : Fl_Progress(x, y, w, h, label) {
    selection_color(FL_SELECTION_COLOR);
  }
  
  void animation_speed(int animation_speed) {animation_speed_ = animation_speed;}
  int animation_speed() const {return animation_speed_;}

  void marquee(bool marquee) {
    marquee_ = marquee;
    if (marquee_) Fl::add_timeout(static_cast<double>(animation_speed_) / 1000, on_marquee_timer_tick, this);
  }
  bool marquee() const {return marquee_;}
  
  int marquee_width() const {return marquee_width_;}
  void marquee_width(int marquee_width) {marquee_width_ = marquee_width;}

  void draw() override {
    Fl_Progress::draw();
    if (marquee_) {
      draw_box(FL_DOWN_BOX, x(), y(), w(), h(), color());
      draw_box(FL_FLAT_BOX, x() + Fl::box_dw(box()) / 2 + marquee_pos_ - 1, y() + Fl::box_dh(box()) / 2 - 1, marquee_width_ - Fl::box_dw(box()) + 2, h() - Fl::box_dh(box()) + 2, selection_color());
    }
  }
  
private:
  static void on_marquee_timer_tick(void* data) {
    auto progress = reinterpret_cast<Fl_Progress_Bar*>(data);
    if (progress->right_) {
      if (progress->marquee_pos_ < (progress->w() - (2 * Fl::box_dw(progress->box()))) - progress->marquee_width_)
        progress->marquee_pos_ = progress->marquee_pos_ + progress->marquee_width_;
      else {
        progress->right_ = false;
        progress->marquee_pos_ = progress->marquee_pos_ - progress->marquee_width_;
      }
    } else {
      if (progress->marquee_pos_ > 0)
        progress->marquee_pos_ = progress->marquee_pos_ - progress->marquee_width_;
      else {
        progress->right_ = true;
        progress->marquee_pos_ = progress->marquee_pos_ + progress->marquee_width_;
      }
    }

    progress->redraw();
    if (progress->marquee()) Fl::repeat_timeout(static_cast<double>(progress->animation_speed_) / 1000, on_marquee_timer_tick, progress);
  }
  
  int animation_speed_ = 200;
  bool marquee_ = false;
  int marquee_pos_ = 0;
  int marquee_width_ = 40;
  bool right_ = true;
};
