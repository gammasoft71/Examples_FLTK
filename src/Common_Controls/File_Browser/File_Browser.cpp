#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_File_Browser.H>
#include <FL/Fl_Window.H>
#if defined(_WIN32)
#include <stdlib.h>
#endif

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 500, 255, "File browser example") {
      file_browser.type(FL_HOLD_BROWSER);
      file_browser.filetype(Fl_File_Browser::FILES);
      file_browser.filter("*.*");
#if defined(_WIN32)
      file_browser.load(getenv("HOMEPATH"));
#else
      file_browser.load(getenv("HOME"));
#endif
      file_browser.callback([](Fl_Widget* sender, void* data) {
        auto file_browser = dynamic_cast<Fl_File_Browser*>(sender);
        auto box = reinterpret_cast<Fl_Box*>(data);
        box->copy_label(file_browser->text(file_browser->value()));
      }, &box1);
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_File_Browser file_browser {10, 10, 480, 200};
    Fl_Box box1 {10, 220, 480, 25, "(none)"};
  };
}

int main(int argc, char *argv[]) {
  Fl_File_Icon::load_system_icons();
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
