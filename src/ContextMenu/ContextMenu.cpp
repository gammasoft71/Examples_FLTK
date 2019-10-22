#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "ContextMenu example") {
    resizable(this);
    
    contextMenu.type(Fl_Menu_Button::POPUP3);
    contextMenu.add("Item 1", "^1", [](Fl_Widget* sender,void* form) {
      cout << "Item 1 selected" << endl;
    }, this);
    contextMenu.add("Item 2", "^2", [](Fl_Widget* sender,void* form) {
      cout << "Item 2 selected" << endl;
    }, this, FL_MENU_DIVIDER);
    contextMenu.add("Item 3", "^3", [](Fl_Widget* sender,void* form) {
      cout << "Item 3 selected" << endl;
    }, this);
  }
  
private:
  Fl_Menu_Button contextMenu {0, 0, 640, 480, nullptr};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
