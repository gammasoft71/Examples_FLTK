#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Message example"} {
      end();
      button_show_message.callback([](Fl_Widget* sender, void* data) {
        fl_message_title("Message");
        fl_message("This is a message description.");
      }, nullptr);
    }
    
  private:
    Fl_Button button_show_message {10, 10, 100, 25, "Message"};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
