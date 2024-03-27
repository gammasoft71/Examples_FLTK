#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Choice example"} {
      button_show_choice.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        window->box_result.copy_label("Result = ");
        fl_message_title("Choice");
        window->box_result.copy_label(fl_choice("Can you answer the question ?", fl_no, fl_yes, nullptr) == 0 ? "Result = No" : "Result = Yes");
      }, this);

      box_result.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Button button_show_choice {10, 10, 100, 25, "Choice"};
    Fl_Box box_result {10, 45, 200, 20, "Result = "};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
