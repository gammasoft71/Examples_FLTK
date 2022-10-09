#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Hello world (box)") {
      box1.align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      box1.labelfont(box1.labelfont() | FL_BOLD | FL_ITALIC);
      box1.labelsize(36);
      box1.labelcolor(fl_rgb_color(0x00, 0x80, 0x00));
      box1.labeltype(FL_SHADOW_LABEL);

      resizable(this);
      position((Fl::w() - w())/2, (Fl::h() - h())/2);
    }
    
  private:
    Fl_Box box1 {0, 0, 300, 300, "Hello, World!"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
