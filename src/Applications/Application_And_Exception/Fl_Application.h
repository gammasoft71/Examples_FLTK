#include <stdexcept>
#include <FL/Fl.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

class Fl_Application {
public:
  static void run(int argc, char *argv[], const Fl_Window& window) {
    Fl::event_dispatch(event_dispatch);
    const_cast<Fl_Window&>(window).show(argc, argv);
    Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
    return Fl::run();
  }
  
private:
  static int event_dispatch(int event, Fl_Window* window) {
    try {
      return Fl::handle_(event, window);
    } catch (const std::exception& e) {
      if (!show_message("Exception occured", e.what())) exit(-1);
    } catch (...) {
      if (!show_message("Unknown exception occured", "(Unknown exception)")) exit(-1);
    }
  }
  
  static bool show_message(const char* title, const char* text) {
    fl_message_icon()->label("X");
    fl_message_icon()->color(fl_rgb_color(255, 0, 0));
    fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
    fl_message_hotspot(false);
    fl_message_title(title);
    return fl_choice("Unhandled exception occured in your application. If you click\nOK, the application will ignore this error and attempt to continue.\nIf you click Cancel, the application will close immediately.\n\n%s", fl_cancel, fl_ok, nullptr, text);
  }
};
