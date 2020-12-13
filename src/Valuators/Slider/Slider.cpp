#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Fill_Slider.H>
#include <FL/Fl_Hor_Slider.H>
#include <FL/Fl_Hor_Fill_Slider.H>
#include <FL/Fl_Hor_Nice_Slider.H>
#include <FL/Fl_Nice_Slider.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 340, "Slider example") {
      end();
      resizable(this);
      
      hor_slider1.maximum(100);
      hor_slider1.callback(on_value_changed, &box1);
      hor_slider1.value(25);
      hor_slider1.do_callback();
      
      hor_fill_slider1.maximum(100);
      hor_fill_slider1.callback(on_value_changed, &box2);
      hor_fill_slider1.value(50);
      hor_fill_slider1.do_callback();
      
      hor_nice_slider1.maximum(100);
      hor_nice_slider1.callback(on_value_changed, &box3);
      hor_nice_slider1.value(75);
      hor_nice_slider1.do_callback();
      
      slider1.maximum(100);
      slider1.callback(on_value_changed, &box4);
      slider1.value(25);
      slider1.do_callback();
      
      fill_slider1.maximum(100);
      fill_slider1.callback(on_value_changed, &box5);
      fill_slider1.value(50);
      fill_slider1.do_callback();
      
      nice_slider1.maximum(100);
      nice_slider1.callback(on_value_changed, &box6);
      nice_slider1.value(75);
      nice_slider1.do_callback();
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box2.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box3.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box4.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box5.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box6.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    static void on_value_changed(Fl_Widget* sender, void* data) {
      reinterpret_cast<Fl_Widget*>(data)->copy_label(to_string(static_cast<int>(dynamic_cast<Fl_Slider*>(sender)->value())).c_str());
    }
    Fl_Hor_Slider hor_slider1 {10, 10, 180, 25};
    Fl_Hor_Fill_Slider hor_fill_slider1 {10, 45, 180, 25};
    Fl_Hor_Nice_Slider hor_nice_slider1 {10, 80, 180, 25};
    Fl_Slider slider1 {40, 115, 25, 180};
    Fl_Fill_Slider fill_slider1 {130, 115, 25, 180};
    Fl_Nice_Slider nice_slider1 {230, 115, 25, 180};
    Fl_Box box1 {FL_DOWN_BOX, 200, 10, 80, 25, ""};
    Fl_Box box2 {FL_DOWN_BOX, 200, 45, 80, 25, ""};
    Fl_Box box3 {FL_DOWN_BOX, 200, 80, 80, 25, ""};
    Fl_Box box4 {FL_DOWN_BOX, 10, 305, 80, 25, ""};
    Fl_Box box5 {FL_DOWN_BOX, 100, 305, 80, 25, ""};
    Fl_Box box6 {FL_DOWN_BOX, 200, 305, 80, 25, ""};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
