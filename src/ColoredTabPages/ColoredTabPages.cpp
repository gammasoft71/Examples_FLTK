#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 390, 270, "TabControl example") {
    this->resizable(this);

    this->tabControl1 = make_shared<Fl_Tabs>(10, 10, 370, 250);

    this->tabPageRed = make_shared<Fl_Group>(20, 30, 350, 220, "Red");
    this->tabPageRed->color(fl_rgb_color(0xFF, 0x00, 0x00));
    this->tabPageRed->end();
    
    this->tabPageGreen = make_shared<Fl_Group>(20, 30, 350, 220, "Green");
    this->tabPageGreen->color(fl_rgb_color(0x00, 0x80, 0x00));
    this->tabPageGreen->end();
    
    this->tabPageBlue = make_shared<Fl_Group>(20, 30, 350, 220, "Blue");
    this->tabPageBlue->color(fl_rgb_color(0x00, 0x00, 0xFF));
    this->tabPageBlue->end();
    
    this->tabPageYellow = make_shared<Fl_Group>(20, 30, 350, 220, "Yellow");
    this->tabPageYellow->color(fl_rgb_color(0xFF, 0xFF, 0x00));
    this->tabPageYellow->end();

    this->tabControl1->end();
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
