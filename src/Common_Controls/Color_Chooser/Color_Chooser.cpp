#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 220, 220, "Color chooser example") {
      uchar red = 0, green = 0, blue = 0;
      Fl::get_color(test_color_box.color(), red, green, blue);
      
      color_chooser.rgb(red / 255.0, green / 255.0, blue / 255.0);
      color_chooser.mode(1);
      color_chooser.callback([](Fl_Widget* sender, void* data) {
        auto color_chooser = dynamic_cast<Fl_Color_Chooser*>(sender);
        auto test_color_box = reinterpret_cast<Fl_Box*>(data);
        test_color_box->color(fl_rgb_color(color_chooser->r() * 255, color_chooser->g() * 255, color_chooser->b() * 255));
        test_color_box->redraw();
      }, &test_color_box);
      
      test_color_box.box(FL_FRAME_BOX);
    }
    
  private:
    Fl_Color_Chooser color_chooser {10, 10, 200, 95};
    Fl_Box test_color_box {10, 115, 200, 95};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
