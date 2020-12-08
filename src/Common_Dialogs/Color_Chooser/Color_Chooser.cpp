#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Color chooser example") {
      resizable(this);
      
      buttonShowMessage.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      buttonShowMessage.callback([](Fl_Widget* sender, void* window) {
        uchar r = 0, g = 0, b = 0;
        Fl::get_color(reinterpret_cast<Main_Window*>(window)->color(), r, g, b);
        if (fl_color_chooser("Color", r, g, b) != 0) {
          reinterpret_cast<Main_Window*>(window)->color(fl_rgb_color(r, g, b));
          reinterpret_cast<Main_Window*>(window)->redraw();
        }
      }, this);
    }
    
  private:
    Fl_Button buttonShowMessage {10, 10, 75, 25, "Color..."};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
