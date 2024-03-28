#include "Fl_Test_Cursor.h"
#include <FL/Fl_Browser.H>
#include <FL/Fl_Window.H>
#include <cstdint>
#include <initializer_list>
#include <utility>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 360, 240, "Cursors example"} {
      for (auto item : initializer_list<pair<const char *, Fl_Cursor>> {{"Default", FL_CURSOR_DEFAULT}, {"Arrow", FL_CURSOR_ARROW}, {"Cross", FL_CURSOR_CROSS}, {"Wait", FL_CURSOR_WAIT}, {"Insert", FL_CURSOR_INSERT}, {"Hand", FL_CURSOR_HAND}, {"Help", FL_CURSOR_HELP}, {"Move", FL_CURSOR_MOVE}, {"North south", FL_CURSOR_NS}, {"West east", FL_CURSOR_WE}, {"North-west south-east", FL_CURSOR_NWSE}, {"North-est south-west", FL_CURSOR_NESW}, {"North", FL_CURSOR_N}, {"North east",FL_CURSOR_NE}, {"East", FL_CURSOR_E}, {"South east", FL_CURSOR_SE}, {"South", FL_CURSOR_S}, {"South west", FL_CURSOR_SW}, {"West", FL_CURSOR_W}, {"North west", FL_CURSOR_NW}, {"None", FL_CURSOR_NONE}})
        cursors_list_box.add(item.first, reinterpret_cast<void*>(item.second));
      cursors_list_box.type(FL_HOLD_BROWSER);
      cursors_list_box.select(1);
      cursors_list_box.callback([](Fl_Widget* sender, void* data) {
        Main_Window* window = reinterpret_cast<Main_Window*>(data);
        if (window->cursors_list_box.value() != 0)
          window->test_cursor.cursor(static_cast<Fl_Cursor>(reinterpret_cast<intptr_t>(window->cursors_list_box.data(window->cursors_list_box.value()))));
      }, this);
      
      test_cursor.box(FL_DOWN_BOX);
      test_cursor.color(FL_BACKGROUND2_COLOR);
    }
    
  private:
    Fl_Browser cursors_list_box {20, 20, 150, 200};
    Fl_Test_Cursor test_cursor {190, 20, 150, 200};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}
