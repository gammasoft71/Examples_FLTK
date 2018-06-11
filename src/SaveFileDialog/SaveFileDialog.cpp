#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "SaveFileDialog example") {
    this->resizable(this);
    
    this->button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->button.callback([](Fl_Widget* sender, void* form) {
      Fl_Native_File_Chooser saveFileDialog;
      saveFileDialog.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
      saveFileDialog.filter("Text File\t*.txt");
      saveFileDialog.directory((std::string(getenv("HOME")) + "/Desktop").c_str());
      saveFileDialog.preset_file("Myfile.txt");
      saveFileDialog.options(Fl_Native_File_Chooser::SAVEAS_CONFIRM | Fl_Native_File_Chooser::NEW_FOLDER);
      if (saveFileDialog.show() == 0)
        ((Form*)form)->label.copy_label((std::string("File = ") + saveFileDialog.filename()).c_str());
    }, this);

    this->label.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
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
