#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 640, 480, "Group example") {
      group1.align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group1.box(FL_BORDER_BOX);

      group2.align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group2.box(FL_BORDER_BOX);
    }
    
  private:
    Fl_Group group1 {10, 10, 305, 460, "Group 1"};
    Fl_End end_group1;
    Fl_Group group2 {325, 10, 305, 460};
    Fl_End end_group2;
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
