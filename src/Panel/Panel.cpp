#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 640, 480, "Panel example") {
    this->resizable(this);
    this->panel1 = std::make_shared<Fl_Scroll>(10, 10, 305, 460);
    this->panel1->end();
    this->panel1->box(FL_BORDER_BOX);
    this->panel2 = std::make_shared<Fl_Scroll>(325, 10, 305, 460);
    this->panel2->box(FL_DOWN_BOX);
  }
  
private:
  std::shared_ptr<Fl_Scroll> panel1;
  std::shared_ptr<Fl_Scroll> panel2;
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
