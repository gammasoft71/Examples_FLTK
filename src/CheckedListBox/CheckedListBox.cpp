#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/Fl_Window.H>

using namespace std;

class Fl_Checked_list_box : public Fl_Check_Browser {
public:
  Fl_Checked_list_box(int x, int y, int w, int h) : Fl_Check_Browser(x, y, w, h) {
    selection_color(FL_SELECTION_COLOR);
  }
  
  int handle(int event) override {
    return Fl_Check_Browser::handle(event);
  }
  
private:
};

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "CheckedListBox example") {
    this->resizable(this);
    for (int index = 0; index < 50; index++) {
      stringstream ss;
      ss << "item " << index;
      checkedListBox.add(ss.str().c_str(), index % 2);
    }
    
    int item = 3;
    checkedListBox.select(&item);
  }
  
private:
  Fl_Checked_list_box checkedListBox {10, 10, 280, 280};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
