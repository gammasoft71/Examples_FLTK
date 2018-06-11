#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "ColorDialog example") {
    this->resizable(this);
    
    this->buttonShowMessage.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->buttonShowMessage.callback([](Fl_Widget* sender, void* form) {
      uchar r = 0, g = 0, b = 0;
      Fl::get_color(((Form*)form)->color(), r, g, b);
      if (fl_color_chooser("Color", r, g, b) != 0) {
        ((Form*)form)->color(fl_rgb_color(r, g, b));
        ((Form*)form)->redraw();
      }
    }, this);
  }
  
private:
  Fl_Button buttonShowMessage {10, 10, 75, 25, "Color..."};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
