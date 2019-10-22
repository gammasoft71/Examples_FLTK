#include <initializer_list>
#include <utility>
#include <FL/Fl.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Window.H>
#include "Fl_Test_Cursor.H"

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 360, 240, "ListBox example") {
    resizable(this);
    for (auto item : initializer_list<pair<const char *, Fl_Cursor>> {{"Application Starting", FL_CURSOR_WAIT}, {"Arrow", FL_CURSOR_ARROW}, {"Close hand", FL_CURSOR_HAND}, {"Contextual menu", FL_CURSOR_DEFAULT}, {"Cross", FL_CURSOR_CROSS}, {"Default cursor", FL_CURSOR_DEFAULT}, {"Disappearing item", FL_CURSOR_DEFAULT}, {"Drag copy", FL_CURSOR_DEFAULT}, {"Drag link", FL_CURSOR_DEFAULT}, {"Hand", FL_CURSOR_HAND}, {"Help", FL_CURSOR_HELP}, {"Horizontal split", FL_CURSOR_NS}, {"I beam", FL_CURSOR_INSERT}, {"No", FL_CURSOR_DEFAULT}, {"No move 2d", FL_CURSOR_DEFAULT}, {"No move horizontal", FL_CURSOR_DEFAULT}, {"No move vertical", FL_CURSOR_DEFAULT}, {"Open hand", FL_CURSOR_HAND}, {"Pan east", FL_CURSOR_E}, {"Pan north east",FL_CURSOR_NE}, {"Pan north", FL_CURSOR_N}, {"Pan north west", FL_CURSOR_NW}, {"Pan south", FL_CURSOR_S}, {"Pan south west", FL_CURSOR_SW}, {"Pan West", FL_CURSOR_W}, {"Size all", FL_CURSOR_MOVE}, {"Size north-east south-west", FL_CURSOR_DEFAULT}, {"Size north south", FL_CURSOR_NS}, {"Size north-west south-east", FL_CURSOR_NWSE}, {"Size west east", FL_CURSOR_WE}, {"Up arrow", FL_CURSOR_DEFAULT}, {"Vertical I beam", FL_CURSOR_INSERT}, {"Vertical split", FL_CURSOR_WE}, {"Wait cursor", FL_CURSOR_WAIT}})
      listBoxCursors.add(item.first, (void*)item.second);
    listBoxCursors.type(FL_HOLD_BROWSER);
    listBoxCursors.select(6);
    listBoxCursors.callback([](Fl_Widget* sender, void* form) {
      if (((Form*)form)->listBoxCursors.value() != 0)
        ((Form*)form)->test_zone.cursor((Fl_Cursor)(intptr_t)((Form*)form)->listBoxCursors.data(((Form*)form)->listBoxCursors.value()));
    }, this);

    test_zone.box(FL_DOWN_BOX);
    test_zone.color(FL_BACKGROUND2_COLOR);
  }
  
private:
  Fl_Browser listBoxCursors {20, 20, 150, 200};
  Fl_Window test_zone {190, 20, 150, 200};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
