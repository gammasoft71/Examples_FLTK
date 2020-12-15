#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Choice example") {
      button_show_choice.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        window->box_result.copy_label("Result = ");
        fl_message_hotspot(0);
        fl_message_icon()->label("!");
        fl_message_icon()->color(fl_rgb_color(255, 255, 0));
        fl_message_icon()->labelcolor(fl_rgb_color(0, 0, 0));
        fl_message_title("Choice");
        if (fl_choice("Hello, World!", fl_cancel, fl_ok, nullptr) == 1)
          window->box_result.copy_label("Result = Ok");
        else
          window->box_result.copy_label("Result = Cancel");
      }, this);

      box_result.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Button button_show_choice {10, 10, 100, 25, "Choice"};
    Fl_Box box_result {10, 45, 200, 20, "Result = "};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
