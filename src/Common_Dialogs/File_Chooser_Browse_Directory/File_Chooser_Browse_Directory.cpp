#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "File Chooser browse directory example") {
      button.callback([](Fl_Widget* sender, void* form) {
        reinterpret_cast<Main_Window*>(form)->box.copy_label("Path = (none)");
        #if defined(_WIN32)
          std::string directory = (string(getenv("HOMEPATH")) + "\\Desktop");
        #else
          std::string directory = (string(getenv("HOME")) + "/Desktop");
        #endif
        const char* result = fl_dir_chooser("Directory browse", directory.c_str());
        if (result != nullptr)
          reinterpret_cast<Main_Window*>(form)->box.copy_label((string("Path = ") + string(result)).c_str());
      }, this);

      box.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Button button {10, 10, 80, 25, "Directory..."};
    Fl_Box box {10, 50, 280, 20, "Path = (none)"};
  };
}

int main(int argc, char *argv[]) {
  Fl_File_Icon::load_system_icons();
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
