#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

auto main() -> int {
  auto window = Fl_Window {340, 180};
  auto box = Fl_Box {20, 40, 300, 100, "Hello, World!"};
  box.box(FL_UP_BOX);
  box.labelfont(FL_BOLD + FL_ITALIC);
  box.labelsize(36);
  box.labeltype(FL_SHADOW_LABEL);
  window.show(argc, argv);
  return Fl::run();
}
