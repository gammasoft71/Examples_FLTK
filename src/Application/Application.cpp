#include <FL/Fl.H>
#include <FL/Fl_Window.H>

int main(int argc, char *argv[]) {
  Fl_Window form(300, 300);
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
