#include <stdexcept>
#include <string>
#include <FL/Fl.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

class Fl_Application final {
public:
  static void run(int argc, char *argv[], const Fl_Window& window) {
    Fl::event_dispatch(event_dispatch);
    const_cast<Fl_Window&>(window).show(argc, argv);
    Fl::run();
  }
  
  static bool show_exception_error(const std::string& title) {
    return show_message(title.c_str(), "(Unknown exception)");
  }
  
  static bool show_exception_error(const std::string& title, const std::exception& e) {
    return show_message(title.c_str(), e.what());
  }
  
private:
  Fl_Application() = default;
  
  static int event_dispatch(int event, Fl_Window* window) {
    try {
      return Fl::handle_(event, window);
    } catch (const std::exception& e) {
      if (!show_exception_error("Exception occured", e)) exit(-1);
    } catch (...) {
      if (!show_exception_error("Unknown exception occured")) exit(-1);
    }
    return 0;
  }

  static bool show_message(const char* title, const char* text) {
    struct Message_Params {
      Message_Params() = default;
      ~Message_Params() {
        fl_message_hotspot(hotspot);
        fl_message_icon()->box(box);
        fl_message_icon()->color(color);
        fl_message_icon()->label(label);
        fl_message_icon()->labelcolor(labelcolor);
        fl_message_icon()->labelfont(labelfont);
        fl_message_icon()->show();
        fl_message_title("");
      }
      
      int hotspot =  fl_message_hotspot();
      Fl_Boxtype box = fl_message_icon()->box();
      Fl_Color color = fl_message_icon()->color();
      Fl_Color labelcolor = fl_message_icon()->labelcolor();
      Fl_Font labelfont = fl_message_icon()->labelfont();
      const char* label = fl_message_icon()->label();
    } message_params;
    
    fl_message_hotspot(false);
    fl_message_icon()->box(FL_ROUND_UP_BOX);
    fl_message_icon()->color(fl_rgb_color(255, 0, 0));
    fl_message_icon()->label("X");
    fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
    fl_message_icon()->labelfont(FL_HELVETICA_BOLD);
    fl_message_title(title);
    return fl_choice("Unhandled exception occured in your application. If you click\n"
                     "Continue, the application will ignore this error and attempt to continue.\n"
                     "If you click Quit, the application will close immediately.\n"
                     "\n"
                     "%s", "&Quit", "&Continue", nullptr, text);
  }
};
