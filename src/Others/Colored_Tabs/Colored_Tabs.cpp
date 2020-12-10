#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 390, 270, "Colored tabs example") {
    tabs = make_unique<Fl_Tabs>(10, 10, 370, 250);

    page_red = make_unique<Fl_Group>(10, 10, 370, 230, "Red");
    page_red->color(FL_RED);
    page_red->end();
    
    page_green = make_unique<Fl_Group>(10, 10, 370, 230, "Green");
    page_green->color(FL_DARK_GREEN);
    page_green->end();
    
    page_blue = make_unique<Fl_Group>(10, 10, 370, 230, "Blue");
    page_blue->color(FL_BLUE);
    page_blue->end();
    
    page_yellow = make_unique<Fl_Group>(10, 10, 370, 230, "Yellow");
    page_yellow->color(FL_YELLOW);
    page_yellow->end();

    tabs->end();

    end();
    resizable(this);
  }
  
private:
  unique_ptr<Fl_Tabs> tabs;
  unique_ptr<Fl_Group> page_red;
  unique_ptr<Fl_Group> page_green;
  unique_ptr<Fl_Group> page_blue;
  unique_ptr<Fl_Group> page_yellow;
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
