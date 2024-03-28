#include <FL/Fl.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 450, 300, "Text editor example"} {
      resizable(text_editor);
      text_editor.buffer(&text_buffer);
      text_buffer.append("Line 1\n");
      text_buffer.append("Line 2\n");
      text_buffer.append("Line 3\n");
      text_buffer.append("Line 4\n");
      text_buffer.append("Line 5\n");
      text_buffer.append("Line 6\n");
      text_buffer.append("Line 7\n");
      text_buffer.append("Line 8\n");
      text_buffer.append("Line 9\n");
      text_buffer.append("Line 10\n");
    }
    
  private:
    Fl_Text_Buffer text_buffer;
    Fl_Text_Editor text_editor {0, 0, 450, 300};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
