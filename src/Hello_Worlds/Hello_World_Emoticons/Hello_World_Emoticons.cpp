#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Hello world (emoticons)") {
      box1.align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box1.labelsize(72);
      auto text_width = 0;
      auto text_height = 0;
      fl_font(box1.labelfont(), box1.labelsize());
      fl_measure(box1.label(), text_width, text_height);
      box1.size(text_width, text_height);
      size(text_width, text_height);
   }
    
  private:
    Fl_Box box1 {0, 0, 300, 300, "\U0001F44B, \U0001F30E\U00002757"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
