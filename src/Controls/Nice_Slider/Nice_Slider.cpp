#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Hor_Nice_Slider.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Nice slider example") {
      slider1.type(FL_HOR_NICE_SLIDER);
      slider1.maximum(200);
      slider1.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        window->progress1.value(window->slider1.value());
        window->box1.copy_label(to_string(static_cast<int>(dynamic_cast<Fl_Slider*>(sender)->value())).c_str());
      }, this);
      slider1.value(100);
      slider1.do_callback();

      progress1.maximum(200);

      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Hor_Nice_Slider slider1 {20, 50, 200, 25};
    Fl_Progress progress1 {20, 100, 200, 25};
    Fl_Box box1 {20, 150, 75, 25};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window form;
  form.show(argc, argv);
  return Fl::run();
}
