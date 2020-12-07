#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Hello world (message)") {
      resizable(this);
      
      button1.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button1.callback([](Fl_Widget* sender, void* window) {
        fl_message("Hello, World!");
      }, this);
    }
    
  private:
    Fl_Button button1 {10, 10, 75, 25, "Click me"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  fl_message_hotspot(0);
  return Fl::run();
}
