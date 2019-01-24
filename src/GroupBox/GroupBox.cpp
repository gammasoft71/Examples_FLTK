#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 640, 480, "GroupBox example") {
    this->resizable(this);
    
    this->groupBox1 = make_shared<Fl_Group>(10, 10, 305, 460, "GroupBox 1");
    this->groupBox1->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
    this->groupBox1->box(FL_BORDER_BOX);
    this->groupBox1->end();

    this->groupBox2 = make_shared<Fl_Group>(325, 10, 305, 460);
    this->groupBox2->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
    this->groupBox2->box(FL_BORDER_BOX);
    this->groupBox2->end();
  }
  
private:
  shared_ptr<Fl_Group> groupBox1;
  shared_ptr<Fl_Group> groupBox2;
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
