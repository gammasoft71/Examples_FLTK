#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Window : public Fl_Window {
  public:
    Window() : Fl_Window(200, 100, 200, 240, "CheckBrowser example") {
      resizable(this);
      
      for (auto index = 0; index < 10; index++)
        checkBrowser.add(("item " + to_string(index)).c_str(), index % 2);
      checkBrowser.when(FL_WHEN_CHANGED);
      checkBrowser.callback([](Fl_Widget* sender, void* window) {
        cout << "checked items = " << reinterpret_cast<Window*>(window)->CheckBrowserToString() << endl;
      }, this);

      cout << "checked items = " << CheckBrowserToString() << endl;
    }
    
  private:
    string CheckBrowserToString() const {
      string checkedItems;
      for (auto item = 1; item <= checkBrowser.nitems(); ++item)
        if (checkBrowser.checked(item)) checkedItems.append((checkedItems.empty() ? "" : ", ")).append(checkBrowser.text(item));
      return checkedItems;
    }
    
    Fl_Check_Browser checkBrowser {20, 20, 160, 200};
  };
}

int main(int argc, char *argv[]) {
  Examples::Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
