#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Input dialog example") {
      button_show_message.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        auto result = fl_input("Message text:", window->box_result.label());
        if (result) window->box_result.copy_label(result);
      }, this);
      
      box_result.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Button button_show_message {10, 10, 75, 25, "Text..."};
    Fl_Box box_result {10, 50, 200, 25, "Default value"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
