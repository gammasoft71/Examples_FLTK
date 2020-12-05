#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "FolderBrowserDialog example") {
    resizable(this);
    
    button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    button.callback([](Fl_Widget* sender, void* form) {
      Fl_Native_File_Chooser folderBrowserDialog;
      folderBrowserDialog.type(Fl_Native_File_Chooser::BROWSE_DIRECTORY);
#if defined(_WIN32)
      folderBrowserDialog.directory((string(getenv("HOMEPATH")) + "\\Desktop").c_str());
#else
      folderBrowserDialog.directory((string(getenv("HOME")) + "/Desktop").c_str());
#endif
      if (folderBrowserDialog.show() == 0)
        ((Form*)form)->label.copy_label((string("Path = ") + folderBrowserDialog.filename()).c_str());
    }, this);

    label.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  }
  
private:
  Fl_Button button {10, 10, 75, 25, "Folder..."};
  Fl_Box label {10, 50, 280, 20, ""};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
