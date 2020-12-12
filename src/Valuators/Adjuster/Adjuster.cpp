#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Adjuster.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Adjuster example") {
      end();
      
      adjuster1.bounds(0, 1);
      adjuster1.value(1);
      adjuster1.soft(false);
      adjuster1.callback(on_value_changed, &box1);
      
      adjuster2.bounds(10, 11);
      adjuster2.value(10);
      adjuster2.soft(false);
      adjuster2.callback(on_value_changed, this);
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box2.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      
      on_value_changed(&adjuster1, &box1);
      on_value_changed(&adjuster2, &box2);
    }
    
  private:
    static void on_value_changed(Fl_Widget* sender, void* window) {
      static string result(' ', 128);
      dynamic_cast<Fl_Valuator*>(sender)->format(result.data());
      reinterpret_cast<Fl_Widget*>(window)->copy_label(result.c_str());
    }
    
    Fl_Adjuster adjuster1 {10, 10, 75, 25};
    Fl_Adjuster adjuster2 {60, 50, 25, 75};
    Fl_Box box1 {FL_DOWN_BOX, 95, 10, 75, 25, ""};
    Fl_Box box2 {FL_DOWN_BOX, 95, 75, 75, 25, ""};
  };
}

int main(int argc, char* argv[]) {
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::run();
}
