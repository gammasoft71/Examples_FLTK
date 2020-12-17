#pragma once

#include <string>
#include <vector>
#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Window.H>

inline int fl_font_chooser(const char* name, Fl_Font& font, int& size, Fl_Color& color, const char* fontset = nullptr, int color_mode = -1) {
  using namespace std;
  using namespace std::literals;

  class Fl_Font_Chooser {
  public:
    Fl_Font_Chooser() {
      dialog_.end();
      int numberOfFont = Fl::set_fonts(font_set_ ? font_set_->c_str() : nullptr);
      for (int index = 0; index < numberOfFont; index++) {
        int fontType = 0;
        string font_name = Fl::get_font_name((Fl_Font)index, &fontType);
        if (fontType) {
          //if (fontType & FL_BOLD) font_name = "@b" + font_name;
          //if (fontType & FL_ITALIC) font_name = "@i" + font_name;
          font_name = "@F" + std::to_string(index) + font_name;
          if (font_name.find("@.") != string::npos) font_name.erase(font_name.find("@."), "@."s.length()); // Suppress subsequent formatting - some MS fonts have '@' in their name
        }
        font_names_.add(font_name.c_str());
      }
      
      font_names_.callback([](Fl_Widget* sender, void* data) {
        auto font_chooser = reinterpret_cast<Fl_Font_Chooser*>(data);
        font_chooser->font_ = font_chooser->font_names_.value() - 1;
        font_chooser->font_view_.labelfont(font_chooser->font_);
        font_chooser->font_view_.redraw();
      }, this);
      
      for (int index = 1; index <= 72; index++)
        font_sizes_.add(to_string(index).c_str());
      
      font_sizes_.callback([](Fl_Widget* sender, void* data) {
        auto font_chooser = reinterpret_cast<Fl_Font_Chooser*>(data);
        font_chooser->size_ = font_chooser->font_sizes_.value() - 1;
        font_chooser->font_view_.labelsize(font_chooser->size_);
        font_chooser->font_view_.redraw();
      }, this);
      
      font_view_.box(FL_DOWN_BOX);
      font_view_.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      
      button_ok_.callback([](Fl_Widget* sender, void* data) {
        auto font_chooser = reinterpret_cast<Fl_Font_Chooser*>(data);
        font_chooser->result_ = 1;
        font_chooser->dialog_.hide();
      }, this);
      
      button_cancel_.shortcut(FL_Escape);
      button_cancel_.callback([](Fl_Widget* sender, void* data) {
        auto font_chooser = reinterpret_cast<Fl_Font_Chooser*>(data);
        font_chooser->result_ = 0;
        font_chooser->dialog_.hide();
      }, this);

      button_color_.callback([](Fl_Widget* sender, void* data) {
        auto font_chooser = reinterpret_cast<Fl_Font_Chooser*>(data);
        uchar r = 0, g = 0, b = 0;
        Fl::get_color(font_chooser->color_, r, g, b);
        if (fl_color_chooser("Color", r, g, b, font_chooser->color_mode_) != 0) {
          font_chooser->color_ = fl_rgb_color(r, g, b);
          font_chooser->font_view_.labelcolor(fl_rgb_color(r, g, b));
          font_chooser->font_view_.redraw();
        }
      }, this);
    }

    Fl_Font_Chooser(const Fl_Font_Chooser&) = delete;
    Fl_Font_Chooser& operator=(const Fl_Font_Chooser&) = delete;

    int show() {
      dialog_.set_modal();
      dialog_.show();
      while (dialog_.visible())
        Fl::wait();
      return result_;
    }
    
    Fl_Font font() const {return font_;}
    void font(Fl_Font f) {
      font_ = f;
      font_names_.value(font_ + 1);
      font_view_.labelfont(font_);
    }

    void font_set(const string& fs) {font_set_ = make_unique<string>(fs);}
    
    string label() const {return dialog_.label();}
    void label(const string& l) {dialog_.label(l.c_str());}
    
    Fl_Fontsize size() const {return size_;}
    void size(Fl_Fontsize s) {
      size_ = s;
      font_sizes_.value(size_ + 1);
      font_view_.labelsize(size_);
    }
    
    Fl_Color color() const {return color_;}
    void color(int c) {
      color_ = c;
      font_view_.labelcolor(color_);
    }
    
    int color_mode() const {return color_mode_;}
    void color_mode(int m) {
      color_mode_ = m;
    }
    
  private:
    Fl_Window dialog_ {100, 200, 550, 430, ""};
    Fl_Hold_Browser font_names_ {10, 10, 390, 170};
    Fl_Hold_Browser font_sizes_ {410, 10, 130, 170};
    Fl_Box font_view_ {10, 190, 530, 180, "The quick brown fox jumps over the lazy dog.\nTHE QUICK BROWN FOX JUMPS OVER THE LAZY DOG."};
    Fl_Return_Button button_ok_ {295, 390, 75, 25, "Ok"};
    Fl_Button button_cancel_ {380, 390, 75, 25, "Cancel"};
    Fl_Button button_color_ {465, 390, 75, 25, "Color..."};

    Fl_Font font_ = FL_HELVETICA;
    int size_ = FL_NORMAL_SIZE;
    Fl_Color color_ = FL_FOREGROUND_COLOR;
    unique_ptr<string> font_set_;
    int color_mode_ = -1;
    int result_ = 0;
  } font_dialog;
  
  font_dialog.font(font);
  if (fontset) font_dialog.font_set(fontset);
  font_dialog.label(name);
  font_dialog.size(size);
  font_dialog.color(color);
  int result_ = font_dialog.show();
  
  if (result_ == 1) {
    font = font_dialog.font();
    size = font_dialog.size();
    color = font_dialog.color();
  }
  return result_;
}
