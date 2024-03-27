#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Secret input example") {
      input1.value("123456");
      input1.when(FL_WHEN_CHANGED);
      input1.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->box1.label(reinterpret_cast<Main_Window*>(window)->input1.value());
      }, this);

      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Secret_Input input1 {10, 10, 100, 25};
    Fl_Box box1 {10, 50, 100, 25, "123456"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
