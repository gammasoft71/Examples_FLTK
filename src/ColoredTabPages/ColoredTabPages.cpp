#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 390, 270, "TabControl example") {
    resizable(this);

    tabControl1 = make_shared<Fl_Tabs>(10, 10, 370, 250);

    tabPageRed = make_shared<Fl_Group>(10, 10, 370, 230, "Red");
    tabPageRed->color(FL_RED);
    tabPageRed->end();
    
    tabPageGreen = make_shared<Fl_Group>(10, 10, 370, 230, "Green");
    tabPageGreen->color(FL_DARK_GREEN);
    tabPageGreen->end();
    
    tabPageBlue = make_shared<Fl_Group>(10, 10, 370, 230, "Blue");
    tabPageBlue->color(FL_BLUE);
    tabPageBlue->end();
    
    tabPageYellow = make_shared<Fl_Group>(10, 10, 370, 230, "Yellow");
    tabPageYellow->color(FL_YELLOW);
    tabPageYellow->end();

    tabControl1->end();
  }
  
private:
  shared_ptr<Fl_Tabs> tabControl1;
  shared_ptr<Fl_Group> tabPageRed;
  shared_ptr<Fl_Group> tabPageGreen;
  shared_ptr<Fl_Group> tabPageBlue;
  shared_ptr<Fl_Group> tabPageYellow;
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
