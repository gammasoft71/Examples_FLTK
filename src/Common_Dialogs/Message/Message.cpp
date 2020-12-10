#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Message example") {
      end();
      resizable(this);
      
      button_show_message.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button_show_message.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        fl_message_icon()->color(fl_rgb_color(0, 0, 255));
        fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
        fl_message_title("Message");
        fl_message("Shows a %s message", "formated");
      }, this);
    }
    
  private:
    Fl_Button button_show_message {10, 10, 100, 25, "Message"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  fl_message_hotspot(0);
  return Fl::run();
}
