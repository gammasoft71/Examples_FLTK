#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Progress.H>

static constexpr int32_t FL_HOR_PROGRESS_BAR = 0;
static constexpr int32_t FL_VERT_PROGRESS_BAR = 1;

class Fl_Progress_Bar : public Fl_Progress {
public:
  Fl_Progress_Bar(int x, int y, int w, int h) : Fl_Progress(x, y, w, h) {
    selection_color(FL_SELECTION_COLOR);
  }
  
  void animation_speed(int animation_speed) {animation_speed_ = animation_speed;}
  int animation_speed() const {return animation_speed_;}

  void marquee(bool marquee) {
    marquee_ = marquee;
    if (marquee_) Fl::add_timeout((double)animation_speed_ / 1000, on_marquee_timer_tick, this);
  }
  bool marquee() const {return marquee_;}
  
  int marquee_width() const {return marquee_width_;}
  void marquee_width(int marquee_width) {marquee_width_ = marquee_width;}

  void draw() override {
    //Fl_Progress::draw();
    draw_box(FL_DOWN_BOX, x(), y(), w(), h(), color());
    if (!marquee()) {
      int progress = 0;
      if (type() == FL_HOR_PROGRESS_BAR) {
        if (maximum() > minimum())  progress = (int)(w() * (value() - minimum()) / (maximum() - minimum()) + 0.5f);
        draw_box(FL_FLAT_BOX, x() + Fl::box_dw(box()) / 2 - 1, y() + Fl::box_dh(box()) / 2 - 1, progress, h() - Fl::box_dh(box()) + 2, active_r() ? selection_color() : fl_inactive(selection_color()));
      } else {
        if (maximum() > minimum())  progress = (int)(h() * (value() - minimum()) / (maximum() - minimum()) + 0.5f);
        draw_box(FL_FLAT_BOX, x() + Fl::box_dw(box()) / 2 - 1, y() + Fl::box_dh(box()) / 2 - 1 + h() - progress, w() - Fl::box_dw(box()) + 2, h() - Fl::box_dh(box()) + 2 - h() + progress, active_r() ? selection_color() : fl_inactive(selection_color()));
      }
    } else {
      draw_box(FL_FLAT_BOX, x() + Fl::box_dw(box()) / 2 + marquee_pos_ - 1, y() + Fl::box_dh(box()) / 2 - 1, marquee_width_ - Fl::box_dw(box()) + 2, h() - Fl::box_dh(box()) + 2, active_r() ? selection_color() : fl_inactive(selection_color()));
    }
  }
  
private:
  static void on_marquee_timer_tick(void* progress) {
    if (((Fl_Progress_Bar*)progress)->right_) {
      if (((Fl_Progress_Bar*)progress)->marquee_pos_ < (((Fl_Progress_Bar*)progress)->w() - (2 * Fl::box_dw(((Fl_Progress_Bar*)progress)->box()))) - ((Fl_Progress_Bar*)progress)->marquee_width_)
        ((Fl_Progress_Bar*)progress)->marquee_pos_ = ((Fl_Progress_Bar*)progress)->marquee_pos_ + ((Fl_Progress_Bar*)progress)->marquee_width_;
      else {
        ((Fl_Progress_Bar*)progress)->right_ = false;
        ((Fl_Progress_Bar*)progress)->marquee_pos_ = ((Fl_Progress_Bar*)progress)->marquee_pos_ - ((Fl_Progress_Bar*)progress)->marquee_width_;
      }
    } else {
      if (((Fl_Progress_Bar*)progress)->marquee_pos_ > 0)
        ((Fl_Progress_Bar*)progress)->marquee_pos_ = ((Fl_Progress_Bar*)progress)->marquee_pos_ - ((Fl_Progress_Bar*)progress)->marquee_width_;
      else {
        ((Fl_Progress_Bar*)progress)->right_ = true;
        ((Fl_Progress_Bar*)progress)->marquee_pos_ = ((Fl_Progress_Bar*)progress)->marquee_pos_ + ((Fl_Progress_Bar*)progress)->marquee_width_;
      }
    }

    ((Fl_Progress_Bar*)progress)->redraw();
    if (((Fl_Progress_Bar*)progress)->marquee()) Fl::repeat_timeout((double)((Fl_Progress_Bar*)progress)->animation_speed_ / 1000, on_marquee_timer_tick, progress);
  }
  
  int animation_speed_ = 200;
  bool marquee_ = false;
  int marquee_pos_ = 0;
  int marquee_width_ = 40;
  bool right_ = true;
};
