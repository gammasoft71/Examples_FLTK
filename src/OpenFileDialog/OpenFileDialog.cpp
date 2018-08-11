#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "OpenFileDialog example") {
    this->resizable(this);
    
    this->button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->button.callback([](Fl_Widget* sender, void* form) {
      Fl_Native_File_Chooser openFileDialog;
      openFileDialog.type(Fl_Native_File_Chooser::BROWSE_FILE);
      openFileDialog.filter("Text File\t*.txt");
      openFileDialog.directory((std::string(getenv("HOME")) + "/Desktop").c_str());
      if (openFileDialog.show() == 0)
        ((Form*)form)->label.copy_label((std::string("File = ") + openFileDialog.filename()).c_str());
    }, this);

    this->label.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  }
  
private:
  Fl_Button button {10, 10, 75, 25, "Open..."};
  Fl_Box label {10, 50, 280, 20, "File = "};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
