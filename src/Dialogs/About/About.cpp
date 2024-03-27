#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "About example"} {
      end();
      button_show_message.callback([](Fl_Widget* sender, void* data) {
        about("About dialog", "About dialog example", "About dialog description.", "1.0.0", "Copyright © 2021 Gammasoft.\nAll rights reserved.");
      }, this);
    }
    
  private:
    static void about(const std::string& name, const std::string& title, const std::string& description, const std::string& version, const std::string& copyright) noexcept {
      fl_message_icon()->label("i");
      fl_message_title(title.c_str());
      fl_choice("%s", nullptr, fl_ok, nullptr, (name + "\n" + version + "\n \n" + copyright + "\n" + description + "\n ").c_str());
    }
    
    Fl_Button button_show_message {10, 10, 100, 25, "About..."};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
