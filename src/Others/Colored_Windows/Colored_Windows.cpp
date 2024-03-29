#include <map>
#include <memory>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {0, 0, 300, 300, "Colored windows"} {
      auto screen_x = 0, screen_y = 0, screen_w = 0, screen_h = 0;
      Fl::screen_xywh(screen_x, screen_y, screen_w, screen_h);
      position(screen_w - 360, 60);
      
      button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        auto colored_window = make_shared<Fl_Window>(window->x, window->y, 300, 300);
        colored_window->color(window->iterator->first);
        colored_window->copy_label(window->iterator->second.c_str());
        colored_window->show();
        window->colored_windows.push_back(colored_window);
        
        window->x = window->y = window->x < 180 ? window->x + 20 : 60;
        window->iterator++;
        if (window->iterator == window->colors.end()) window->iterator = window->colors.begin();
      }, this);
    }
    
    void hide() override {
      Fl_Window::hide();
      exit(0);
    }

  private:
    Fl_Button button {10, 10, 75, 25, "Create"};
    map<Fl_Color, string> colors {{FL_BLACK, "FL_BLACK"}, {FL_RED, "FL_RED"}, {FL_GREEN, "FL_GREEN"}, {FL_YELLOW, "FL_YELLOW"}, {FL_BLUE, "FL_BLUE"}, {FL_MAGENTA, "FL_MAGENTA"}, {FL_CYAN, "FL_CYAN"}, {FL_DARK_RED, "FL_DARK_RED"}, {FL_DARK_GREEN, "FL_DARK_GREEN"}, {FL_DARK_YELLOW, "FL_DARK_YELLOW"}, {FL_DARK_BLUE, "FL_DARK_BLUE"}, {FL_DARK_MAGENTA, "FL_DARK_MAGENTA"}, {FL_DARK_CYAN, "FL_DARK_CYAN"}, {FL_WHITE, "FL_WHITE"}};
    map<Fl_Color, string>::iterator iterator = colors.begin();
    vector<shared_ptr<Fl_Window>> colored_windows;
    int x = 60;
    int y = 60;
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
