#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 640, 480, "Group example"} {
      group1.align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group1.box(FL_BORDER_BOX);

      group2.align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group2.box(FL_BORDER_BOX);
    }
    
  private:
    Fl_Group group1 {10, 25, 305, 445, "Group 1"};
    Fl_End end_group1;
    Fl_Group group2 {325, 25, 305, 445};
    Fl_End end_group2;
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
