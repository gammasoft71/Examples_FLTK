#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class MainWindow : public Fl_Window {
  public:
    MainWindow() : Fl_Window(200, 100, 300, 300, "Box example") {
      resizable(this);
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Box box1 {10, 10, 75, 25, "box1"};
  };
}

int main(int argc, char *argv[]) {
  Examples::MainWindow window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
