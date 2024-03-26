#include <FL/Fl.H>
#include <FL/Fl_Window.H>

auto main(int argc, char *argv[]) -> int {
  auto window = Fl_Window {300, 300};
  window.show(argc, argv);
  return Fl::run();
}
