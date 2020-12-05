#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "SaveFileDialog example") {
    resizable(this);
    
    button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    button.callback([](Fl_Widget* sender, void* form) {
      Fl_Native_File_Chooser saveFileDialog;
      saveFileDialog.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
      saveFileDialog.filter("Text File\t*.txt");
#if defined(_WIN32)
      saveFileDialog.directory((string(getenv("HOMEPATH")) + "\\Desktop").c_str());
#else
      saveFileDialog.directory((string(getenv("HOME")) + "/Desktop").c_str());
#endif
      saveFileDialog.preset_file("Myfile.txt");
      saveFileDialog.options(Fl_Native_File_Chooser::SAVEAS_CONFIRM | Fl_Native_File_Chooser::NEW_FOLDER);
      if (saveFileDialog.show() == 0)
        ((Form*)form)->label.copy_label((string("File = ") + saveFileDialog.filename()).c_str());
    }, this);

    label.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  }
  
private:
  Fl_Button button {10, 10, 75, 25, "Save..."};
  Fl_Box label {10, 50, 280, 20, ""};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
