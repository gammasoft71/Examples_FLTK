#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Alert example"} {
      end();
      button_show_message.callback([](Fl_Widget* sender, void* data) {
        fl_message_title("Alert");
        fl_alert("This is a warning description.");
      }, this);
    }
    
  private:
    Fl_Button button_show_message {10, 10, 100, 25, "Alert"};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
