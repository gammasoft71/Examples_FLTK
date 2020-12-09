#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::filesystem;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Hello world (say)") {
      std::ofstream file(temp_directory_path()/"say.cmd");
#if _WIN32
      file << "@echo Set Speaker=CreateObject(\"sapi.spvoice\") > %TEMP%\\say.vbs\n@echo Speaker.Speak %* >> %TEMP%\\say.vbs\n@%TEMP%\\say.vbs";
#elif __APPLE__
      file << "say $*";
#else
      file << "spd-say $*";
#endif
      permissions(temp_directory_path()/"say.cmd", perms::owner_all);

      resizable(this);
      
      button1.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button1.callback([](Fl_Widget* sender, void* window) {
        system(((temp_directory_path()/"say.cmd").string() + " \"Hello, World!\"").c_str());
      }, this);
    }
    
  private:
    Fl_Button button1 {10, 10, 75, 25, "Say..."};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  fl_message_hotspot(0);
  return Fl::run();
}
