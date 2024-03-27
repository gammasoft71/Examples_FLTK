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
    Main_Window() : Fl_Window {200, 100, 300, 300, "Nattive File chooser browse file example"} {
      button.callback([](Fl_Widget* sender, void* window) {
        auto dialog = Fl_Native_File_Chooser {};
        dialog.type(Fl_Native_File_Chooser::BROWSE_FILE);
        dialog.filter("Text File\t*.txt");
  #if defined(_WIN32)
        dialog.directory((string {getenv("HOMEPATH")} + "\\Desktop").c_str());
  #else
        dialog.directory((string {getenv("HOME")} + "/Desktop").c_str());
  #endif
        if (dialog.show() == 0) reinterpret_cast<Main_Window*>(window)->label.copy_label((string {"File = "} + dialog.filename()).c_str());
      }, this);

      label.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    }
    
  private:
    Fl_Button button {10, 10, 75, 25, "Open..."};
    Fl_Box label {10, 50, 280, 20, "File = "};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
