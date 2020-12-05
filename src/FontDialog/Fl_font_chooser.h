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

inline int fl_font_chooser(const char* name, Fl_Font& font, int& size, Fl_Color& color, const char* fontset = nullptr) {
  using namespace std;
  using namespace std::literals;

  class Fl_Font_Chooser {
  public:
    Fl_Font_Chooser() {
      int numberOfFont = Fl::set_fonts(fontSet ? fontSet->c_str() : nullptr);
      for (int index = 0; index < numberOfFont; index++) {
        int fontType = 0;
        string fontName = Fl::get_font_name((Fl_Font)index, &fontType);
        if (fontType) {
          if (fontType & FL_BOLD) fontName= "@b" + fontName;
          if (fontType & FL_ITALIC) fontName= "@i" + fontName;
          if (fontName.find("@.") != string::npos) fontName.erase(fontName.find("@."), "@."s.length()); // Suppress subsequent formatting - some MS fonts have '@' in their name
        }
        fontNames.add(fontName.c_str());
      }
      
      fontNames.callback([](Fl_Widget* sender, void* fontChooser) {
        ((Fl_Font_Chooser*)fontChooser)->currentFont = ((Fl_Font_Chooser*)fontChooser)->fontNames.value() - 1;
        ((Fl_Font_Chooser*)fontChooser)->fontView.labelfont(((Fl_Font_Chooser*)fontChooser)->currentFont);
        ((Fl_Font_Chooser*)fontChooser)->fontView.redraw();
      }, this);
      
      for (int index = 1; index <= 72; index++)
        fontSizes.add(to_string(index).c_str());
      
      fontSizes.callback([](Fl_Widget* sender, void* fontChooser) {
        ((Fl_Font_Chooser*)fontChooser)->currentSize = ((Fl_Font_Chooser*)fontChooser)->fontSizes.value() - 1;
        ((Fl_Font_Chooser*)fontChooser)->fontView.labelsize(((Fl_Font_Chooser*)fontChooser)->currentSize);
        ((Fl_Font_Chooser*)fontChooser)->fontView.redraw();
      }, this);
      
      fontView.box(FL_DOWN_BOX);
      fontView.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      
      buttonOk.callback([](Fl_Widget* sender, void* fontChooser) {
        ((Fl_Font_Chooser*)fontChooser)->result = 1;
        ((Fl_Font_Chooser*)fontChooser)->dialog.hide();
      }, this);
      
      buttonCancel.shortcut(FL_Escape);
      buttonCancel.callback([](Fl_Widget* sender, void* fontChooser) {
        ((Fl_Font_Chooser*)fontChooser)->result = 0;
        ((Fl_Font_Chooser*)fontChooser)->dialog.hide();
      }, this);

      buttonColor.callback([](Fl_Widget* sender, void* fontChooser) {
        uchar r = 0, g = 0, b = 0;
        Fl::get_color(((Fl_Font_Chooser*)fontChooser)->currentColor, r, g, b);
        if (fl_color_chooser("Color", r, g, b) != 0) {
          ((Fl_Font_Chooser*)fontChooser)->currentColor = fl_rgb_color(r, g, b);
          ((Fl_Font_Chooser*)fontChooser)->fontView.labelcolor(fl_rgb_color(r, g, b));
          ((Fl_Font_Chooser*)fontChooser)->fontView.redraw();
        }
      }, this);
    }

    Fl_Font_Chooser(const Fl_Font_Chooser&) = delete;
    Fl_Font_Chooser& operator=(const Fl_Font_Chooser&) = delete;

    int show() {
      dialog.set_modal();
      dialog.show();
      while (dialog.visible())
        Fl::wait();
      return result;
    }
    
    Fl_Font font() const {return currentFont;}
    void font(Fl_Font f) {
      currentFont = f;
      fontNames.value(currentFont + 1);
      fontView.labelfont(currentFont);
    }

    void font_set(const string& fs) {fontSet = make_unique<string>(fs);}
    
    string label() const {return dialog.label();}
    void label(const string& l) {dialog.label(l.c_str());}
    
    Fl_Fontsize size() const {return currentSize;}
    void size(Fl_Fontsize s) {
      currentSize = s;
      fontSizes.value(currentSize + 1);
      fontView.labelsize(currentSize);
    }
    
    Fl_Color color() const {return currentColor;}
    void color(int c) {
      currentColor = c;
      fontView.labelcolor(currentColor);
    }

  private:
    Fl_Window dialog {100, 200, 550, 430, ""};
    Fl_Hold_Browser fontNames {10, 10, 390, 170};
    Fl_Hold_Browser fontSizes {410, 10, 130, 170};
    Fl_Box fontView {10, 190, 530, 180, "The quick brown fox jumps over the lazy dog.\nTHE QUICK BROWN FOX JUMPS OVER THE LAZY DOG."};
    Fl_Return_Button buttonOk {295, 390, 75, 25, "Ok"};
    Fl_Button buttonCancel {380, 390, 75, 25, "Cancel"};
    Fl_Button buttonColor {465, 390, 75, 25, "Color..."};

    Fl_Font currentFont = FL_HELVETICA;
    int currentSize = FL_NORMAL_SIZE;
    Fl_Color currentColor = FL_FOREGROUND_COLOR;
    unique_ptr<string> fontSet;
    int result = 0;
  } fontDialog;
  
  fontDialog.font(font);
  if (fontset) fontDialog.font_set(fontset);
  fontDialog.label(name);
  fontDialog.size(size);
  fontDialog.color(color);
  int result = fontDialog.show();
  
  if (result == 1) {
    font = fontDialog.font();
    size = fontDialog.size();
    color = fontDialog.color();
  }
  return result;
}
