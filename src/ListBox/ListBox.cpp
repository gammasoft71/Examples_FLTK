#include <initializer_list>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 360, 240, "ListBox example") {
    resizable(this);
    
    listBoxLeft.type(FL_HOLD_BROWSER);
    for (auto item : {"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"})
      listBoxLeft.add(item);
    listBoxLeft.select(1);
    listBoxLeft.callback([](Fl_Widget* sender, void* form) {
      if (((Form*)form)->listBoxLeft.value() != 0) {
        ((Form*)form)->listBoxRight.add(((Form*)form)->listBoxLeft.text(((Form*)form)->listBoxLeft.value()));
        ((Form*)form)->listBoxRight.value(0);
        ((Form*)form)->listBoxLeft.remove(((Form*)form)->listBoxLeft.value());
        ((Form*)form)->listBoxRight.sort();
      }
    }, this);

    listBoxRight.type(FL_HOLD_BROWSER);
    listBoxRight.sort();
    listBoxRight.callback([](Fl_Widget* sender, void* form) {
      if (((Form*)form)->listBoxRight.value() != 0) {
        ((Form*)form)->listBoxLeft.add(((Form*)form)->listBoxRight.text(((Form*)form)->listBoxRight.value()));
        ((Form*)form)->listBoxLeft.value(0);
        ((Form*)form)->listBoxRight.remove(((Form*)form)->listBoxRight.value());
      }
    }, this);

  }
  
private:
  Fl_Browser listBoxLeft {20, 20, 150, 200};
  Fl_Browser listBoxRight {190, 20, 150, 200};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
