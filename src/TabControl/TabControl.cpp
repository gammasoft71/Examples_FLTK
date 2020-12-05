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

    tabPage1 = make_shared<Fl_Group>(10, 30, 370, 230, "tabPage1");
    tabPage1->end();
    
    tabPage2 = make_shared<Fl_Group>(10, 30, 370, 230, "tabPage2");
    tabPage2->end();
    
    tabPage3 = make_shared<Fl_Group>(10, 30, 370, 230, "tabPage3");
    tabPage3->end();

    tabControl1->end();
  }
  
private:
  shared_ptr<Fl_Tabs> tabControl1;
  shared_ptr<Fl_Group> tabPage1;
  shared_ptr<Fl_Group> tabPage2;
  shared_ptr<Fl_Group> tabPage3;
};

int main(int argc, char *argv[]) {
  //Fl::scheme("gtk+");
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
