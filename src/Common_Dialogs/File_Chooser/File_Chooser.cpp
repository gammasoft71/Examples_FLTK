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
    Main_Window() : Fl_Window(200, 100, 300, 300, "File Chooser example") {
      resizable(this);
      
      button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button.callback([](Fl_Widget* sender, void* form) {
        #if defined(_WIN32)
          std::string directory = (string(getenv("HOMEPATH")) + "\\Desktop");
        #else
          std::string directory = (string(getenv("HOME")) + "/Desktop");
        #endif
        const char* result = fl_file_chooser("Open File", "Text File (*.txt)", directory.c_str());
        if (result != nullptr)
          reinterpret_cast<Main_Window*>(form)->box.copy_label((string("File = ") + string(result)).c_str());
      }, this);

      box.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Button button {10, 10, 75, 25, "Open..."};
    Fl_Box box {10, 50, 280, 20, "File = "};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
