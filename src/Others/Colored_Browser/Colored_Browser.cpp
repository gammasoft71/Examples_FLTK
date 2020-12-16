#include <initializer_list>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 240, 340, "Colored browser example") {
      browser.type(FL_HOLD_BROWSER);
      for (auto item : {"@C0Black text", "@C1Red text", "@C2Green text", "@C3Blue text", "@C4Yellow text", "@C5Magenta text", "@C6Cyan text", "@C7White text", "@C8Dark gray text", "@C9Dark red text", "@C10Dark green text", "@C11Dark blue text", "@C12Dark yellow text", "@C13Dark magenta text", "@C14Dark cyan text"})
        browser.add(item);
      for (auto item : {"@B0Black background", "@B1Red background", "@B2Green background", "@B3Blue background", "@B4Yellow background", "@B5Magenta background", "@B6Cyan background", "@B7White background", "@B8Dark gray background", "@B9Dark red background", "@B10Dark green background", "@B11Dark blue background", "@B12Dark yellow background", "@B13Dark magenta background", "@B14Dark cyan background"})
        browser.add(item);
    }
    
  private:
    Fl_Browser browser {20, 20, 200, 300};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
