#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 200, 240, "Check browser example") {
      end();
      resizable(check_browser);
      
      for (auto index = 0; index < 10; index++)
        check_browser.add(("item " + to_string(index)).c_str(), index % 2);
      check_browser.when(FL_WHEN_CHANGED);
      check_browser.callback([](Fl_Widget* sender, void* window) {
        cout << "checked items = " << reinterpret_cast<Main_Window*>(window)->check_browser_to_string() << endl;
      }, this);

      cout << "checked items = " << check_browser_to_string() << endl;
    }
    
  private:
    string check_browser_to_string() const {
      string checkedItems;
      for (auto item = 1; item <= check_browser.nitems(); ++item)
        if (check_browser.checked(item)) checkedItems.append((checkedItems.empty() ? "" : ", ")).append(check_browser.text(item));
      return checkedItems;
    }
    
    Fl_Check_Browser check_browser {20, 20, 160, 200};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
