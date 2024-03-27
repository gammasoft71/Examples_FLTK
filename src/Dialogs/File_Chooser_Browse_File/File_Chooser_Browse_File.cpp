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
    Main_Window() : Fl_Window {200, 100, 300, 300, "File Chooser browse file example"} {
      button.callback([](Fl_Widget* sender, void* form) {
        reinterpret_cast<Main_Window*>(form)->box.copy_label("File = (none)");
        #if defined(_WIN32)
        auto directory = string {getenv("HOMEPATH")} + "\\Desktop";
        #else
        auto directory = string {getenv("HOME")} + "/Desktop";
        #endif
        auto result = fl_file_chooser("Open File", "Text File (*.txt)", directory.c_str());
        if (result != nullptr) reinterpret_cast<Main_Window*>(form)->box.copy_label((string {"File = "} + result).c_str());
      }, this);

      box.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Button button {10, 10, 75, 25, "Open..."};
    Fl_Box box {10, 50, 280, 20, "File = (none)"};
  };
}

auto main(int argc, char *argv[]) -> int {
  Fl_File_Icon::load_system_icons();
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
