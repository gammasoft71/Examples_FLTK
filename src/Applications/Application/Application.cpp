#include <FL/Fl.H>
#include <FL/Fl_Window.H>

int main(int argc, char *argv[]) {
  Fl_Window window(300, 300);
  window.show(argc, argv);
  return Fl::run();
}
