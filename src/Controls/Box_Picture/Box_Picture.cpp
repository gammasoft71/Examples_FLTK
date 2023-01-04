#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Window.H>
#include "logo.xpm"

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Box with picture example") {
      resizable(box1);

      box1.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box1.box(Fl_Boxtype::FL_BORDER_BOX);
      box1.box(FL_GTK_UP_BOX);
      box1.image(&picture);
    }
    
  private:
    Fl_Box box1 {20, 20, 260, 260};
    Fl_Pixmap picture {logo_xpm};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
