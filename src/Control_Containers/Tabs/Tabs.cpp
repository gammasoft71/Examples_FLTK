#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Window.H>

using namespace std;

class Main_Window : public Fl_Window {
public:
  Main_Window() : Fl_Window(200, 100, 390, 270, "Tabs example") {
    tabs1 = make_unique<Fl_Tabs>(10, 10, 370, 250);

    page1 = make_unique<Fl_Group>(10, 30, 370, 230, "Page1");
    page1->end();
    
    page2 = make_unique<Fl_Group>(10, 30, 370, 230, "Page2");
    page2->end();
    
    page3 = make_unique<Fl_Group>(10, 30, 370, 230, "Page3");
    page3->end();
  }
  
private:
  unique_ptr<Fl_Tabs> tabs1;
  unique_ptr<Fl_Group> page1;
  unique_ptr<Fl_Group> page2;
  unique_ptr<Fl_Group> page3;
};

int main(int argc, char *argv[]) {
  Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
