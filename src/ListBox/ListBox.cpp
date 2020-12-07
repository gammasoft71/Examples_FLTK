#include <initializer_list>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 360, 240, "ListBox example") {
      resizable(this);
      
      listBoxLeft.type(FL_HOLD_BROWSER);
      for (auto item : {"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"})
        listBoxLeft.add(item);
      listBoxLeft.select(1);
      listBoxLeft.callback([](Fl_Widget* sender, void* data) {
        Main_Window* window = reinterpret_cast<Main_Window*>(data);
        if (window->listBoxLeft.value() != 0) {
          window->listBoxRight.add(window->listBoxLeft.text(window->listBoxLeft.value()));
          window->listBoxRight.value(0);
          window->listBoxLeft.remove(window->listBoxLeft.value());
          window->listBoxRight.sort();
        }
      }, this);
      
      listBoxRight.type(FL_HOLD_BROWSER);
      listBoxRight.sort();
      listBoxRight.callback([](Fl_Widget* sender, void* data) {
        Main_Window* window = reinterpret_cast<Main_Window*>(data);
        if (window->listBoxRight.value() != 0) {
          window->listBoxLeft.add(window->listBoxRight.text(window->listBoxRight.value()));
          window->listBoxLeft.value(0);
          window->listBoxRight.remove(window->listBoxRight.value());
        }
      }, this);
      
    }
    
  private:
    Fl_Browser listBoxLeft {20, 20, 150, 200};
    Fl_Browser listBoxRight {190, 20, 150, 200};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
