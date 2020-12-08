#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Native file chooser browse directory example") {
      resizable(this);
      
      button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button.callback([](Fl_Widget* sender, void* window) {
        Fl_Native_File_Chooser dialog;
        dialog.type(Fl_Native_File_Chooser::BROWSE_DIRECTORY);
        // Workaround : Disable all files on macos...
        dialog.filter("/");
  #if defined(_WIN32)
        dialog.directory((string(getenv("HOMEPATH")) + "\\Desktop").c_str());
  #else
        dialog.directory((string(getenv("HOME")) + "/Desktop").c_str());
  #endif
        dialog.options(Fl_Native_File_Chooser::Option::NO_OPTIONS);
        if (dialog.show() == 0)
          reinterpret_cast<Main_Window*>(window)->label.copy_label((string("Path = ") + dialog.filename()).c_str());
      }, this);

      label.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Button button {10, 10, 75, 25, "Folder..."};
    Fl_Box label {10, 50, 280, 20, ""};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
