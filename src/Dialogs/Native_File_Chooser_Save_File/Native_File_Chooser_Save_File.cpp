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
    Main_Window() : Fl_Window(200, 100, 300, 300, "Native file chooser save file example") {
      button.callback([](Fl_Widget* sender, void* window) {
        Fl_Native_File_Chooser saveFileDialog;
        saveFileDialog.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
        saveFileDialog.filter("Text File\t*.txt");
  #if defined(_WIN32)
        saveFileDialog.directory((string(getenv("HOMEPATH")) + "\\Desktop").c_str());
  #else
        saveFileDialog.directory((string(getenv("HOME")) + "/Desktop").c_str());
  #endif
        saveFileDialog.preset_file("My_File.txt");
        saveFileDialog.options(Fl_Native_File_Chooser::SAVEAS_CONFIRM | Fl_Native_File_Chooser::NEW_FOLDER);
        if (saveFileDialog.show() == 0)
          reinterpret_cast<Main_Window*>(window)->box.copy_label((string("File = ") + saveFileDialog.filename()).c_str());
      }, this);

      box.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Button button {10, 10, 75, 25, "Save..."};
    Fl_Box box {10, 50, 280, 20, ""};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
