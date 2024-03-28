#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 200, 240, "Check browser example"} {
      resizable(check_browser);
      
      for (auto index = 0; index < 10; index++)
        check_browser.add(("item " + to_string(index + 1)).c_str(), index % 2);
      check_browser.when(FL_WHEN_CHANGED);
      check_browser.callback([](Fl_Widget* sender, void* window) {
        cout << "checked items = " << reinterpret_cast<Main_Window*>(window)->check_browser_to_string() << endl;
      }, this);

      cout << "checked items = " << check_browser_to_string() << endl;
    }
    
  private:
    string check_browser_to_string() const noexcept {
      string checked_items;
      for (auto item = 0; item < check_browser.nitems(); ++item)
        if (check_browser.checked(item + 1)) checked_items.append((checked_items.empty() ? "" : ", ")).append(check_browser.text(item + 1));
      return checked_items.empty() ? "(none)" : checked_items;
    }
    
    Fl_Check_Browser check_browser {20, 20, 160, 200};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
