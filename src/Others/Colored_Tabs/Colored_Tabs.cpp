#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 390, 270, "Colored tabs example") {
    page_red.color(FL_RED);
    page_green.color(FL_DARK_GREEN);
    page_blue.color(FL_BLUE);
    page_yellow.color(FL_YELLOW);
  }
  
private:
  Fl_Tabs tabs {10, 10, 370, 250};
  Fl_Group page_red {10, 10, 370, 230, "Red"};
  Fl_End end_page_red;
  Fl_Group page_green {10, 10, 370, 230, "Green"};
  Fl_End end_page_green;
  Fl_Group page_blue {10, 10, 370, 230, "Blue"};
  Fl_End end_page_blue;
  Fl_Group page_yellow {10, 10, 370, 230, "Yellow"};
  Fl_End end_page_yellow;
  Fl_End end_tabs;
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  return Fl::run();
}
