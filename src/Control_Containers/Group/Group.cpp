#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 640, 480, "Group example") {
      groupBox1 = make_shared<Fl_Group>(10, 10, 305, 460, "Group 1");
      groupBox1->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
      groupBox1->box(FL_BORDER_BOX);
      groupBox1->end();

      groupBox2 = make_shared<Fl_Group>(325, 10, 305, 460);
      groupBox2->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
      groupBox2->box(FL_BORDER_BOX);
      groupBox2->end();
    }
    
  private:
    shared_ptr<Fl_Group> groupBox1;
    shared_ptr<Fl_Group> groupBox2;
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
