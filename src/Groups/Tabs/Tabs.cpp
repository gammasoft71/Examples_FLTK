#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Window.H>

class Main_Window : public Fl_Window {
public:
  Main_Window() : Fl_Window(200, 100, 390, 270, "Tabs example") {}
  
private:
  Fl_Tabs tabs {10, 10, 370, 250};
  Fl_Group page1 {10, 30, 370, 230, "Page1"};
  Fl_End end_page1;
  Fl_Group page2 {10, 30, 370, 230, "Page2"};
  Fl_End end_page2;
  Fl_Group page3 {10, 30, 370, 230, "Page3"};
  Fl_End end_page3;
  Fl_End end_tabs;
};

int main(int argc, char *argv[]) {
  Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
