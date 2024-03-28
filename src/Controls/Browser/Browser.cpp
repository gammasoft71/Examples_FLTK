#include <initializer_list>
#include <FL/Fl.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 360, 240, "Browser example"} {
      browser_left.type(FL_HOLD_BROWSER);
      for (auto item : {"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"})
        browser_left.add(item);
      browser_left.select(1);
      browser_left.callback([](Fl_Widget* sender, void* data) {
        Main_Window* window = reinterpret_cast<Main_Window*>(data);
        if (window->browser_left.value() == 0) return;
        window->browser_right.add(window->browser_left.text(window->browser_left.value()));
        window->browser_right.value(0);
        window->browser_left.remove(window->browser_left.value());
        window->browser_right.sort();
      }, this);
      
      browser_right.type(FL_HOLD_BROWSER);
      browser_right.sort();
      browser_right.callback([](Fl_Widget* sender, void* data) {
        Main_Window* window = reinterpret_cast<Main_Window*>(data);
        if (window->browser_right.value() == 0) return
        window->browser_left.add(window->browser_right.text(window->browser_right.value()));
        window->browser_left.value(0);
        window->browser_right.remove(window->browser_right.value());
      }, this);
    }
    
  private:
    Fl_Browser browser_left {20, 20, 150, 200};
    Fl_Browser browser_right {190, 20, 150, 200};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
