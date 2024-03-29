#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 450, 300, "Colored text display example"} {
      resizable(text_display);
      text_display.buffer(&text_buffer);
      text_display.highlight_data(&style_buffer, style_table.data(), static_cast<int>(style_table.size()), 'A', 0, 0);
      text_buffer.append("Default line\n");
      style_buffer.append("AAAAAAAAAAAA\n");
      text_buffer.append("Red line\n");
      style_buffer.append("BBBBBBBB\n");
      text_buffer.append("Green line\n");
      style_buffer.append("CCCCCCCCCC\n");
      text_buffer.append("Blue line\n");
      style_buffer.append("DDDDDDDDD\n");
      text_buffer.append("Magenta line\n");
      style_buffer.append("EEEEEEEEEEEE\n");
    }
    
  private:
    std::vector<Fl_Text_Display::Style_Table_Entry> style_table = {
      {FL_FOREGROUND_COLOR, FL_HELVETICA, FL_NORMAL_SIZE},
      {FL_RED, FL_HELVETICA, FL_NORMAL_SIZE},
      {FL_DARK_GREEN, FL_HELVETICA, FL_NORMAL_SIZE},
      {FL_BLUE, FL_HELVETICA, FL_NORMAL_SIZE},
      {FL_MAGENTA, FL_HELVETICA, FL_NORMAL_SIZE},
    };
    Fl_Text_Buffer text_buffer;
    Fl_Text_Buffer style_buffer;
    Fl_Text_Display text_display {0, 0, 450, 300};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
