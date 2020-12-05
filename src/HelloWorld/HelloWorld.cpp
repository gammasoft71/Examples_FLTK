#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

namespace Examples {
#if defined(__APPLE__)
  float points_to_native_font_graphics_untit(float size) {
    return size / 72.0f * 96.0f;  // font is in pixels and not in points
  }
#else
  float points_to_native_font_graphics_untit(float size) {
    return size;  // font is in points
  }
#endif

  class Window : public Fl_Window {
  public:
    Window() : Fl_Window(200, 100, 300, 300, "My first application") {
      box1.align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box1.labelfont(FL_HELVETICA_BOLD_ITALIC);
      box1.labelsize(points_to_native_font_graphics_untit(32));
      box1.labelcolor(fl_rgb_color(0x00, 0x80, 0x00));
      
      resizable(this);
      position((Fl::w() - w())/2, (Fl::h() - h())/2);
    }
    
  private:
    Fl_Box box1 {5, 100, 290, 100, "Hello, World!"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
