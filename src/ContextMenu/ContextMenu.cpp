#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Form : public Fl_Window {
  public:
    Form() : Fl_Window(200, 100, 300, 300, "ContextMenu example") {
      resizable(textDisplay1);

      textBuffer.append("Right click to show menu\n");
      textDisplay1.buffer(&textBuffer);
      textDisplay1.show_cursor(0);

      Fl_Menu_Item items[] = {
        {"&File", 0, nullptr, nullptr, FL_SUBMENU},
          {"&New", FL_COMMAND + 'n', &Form::OnMenuItemClick, this},
          {"&Open", FL_COMMAND + 'o', &Form::OnMenuItemClick, this},
          {"Open &recent", 0, nullptr, nullptr, FL_SUBMENU},
            {"File 1", 0, &Form::OnMenuItemClick, this},
            {"File 2", 0, &Form::OnMenuItemClick, this},
            {"File 3", 0, &Form::OnMenuItemClick, this},
            {"File 4", 0, &Form::OnMenuItemClick, this},
            {"File 5", 0, &Form::OnMenuItemClick, this},
            {0},
          {"&Close", FL_COMMAND + 'w', &Form::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"&Save", FL_COMMAND + 's', &Form::OnMenuItemClick, this},
          {"Save &as...", 0, &Form::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"Page setup...", FL_COMMAND + FL_SHIFT + 'p', &Form::OnMenuItemClick, this},
          {"&Print", FL_COMMAND + 'p', &Form::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"&Quit", FL_COMMAND + 'q', &Form::OnMenuItemClick, this},
          {0},
        {"&Edit", 0, nullptr, nullptr, FL_SUBMENU},
          {"&Undo", FL_COMMAND + 'z', &Form::OnMenuItemClick, this},
          {"&Redo", FL_COMMAND + FL_SHIFT + 'z', &Form::OnMenuItemClick, this},
          {"C&ut", FL_COMMAND + 'x', Form::OnMenuItemClick, this},
          {"&Copy", FL_COMMAND + 'c', Form::OnMenuItemClick, this},
          {"&Paste", FL_COMMAND + 'v', Form::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"Select &all", FL_COMMAND + 'a', Form::OnMenuItemClick, this},
          {0},
        {"&View", 0, nullptr, nullptr, FL_SUBMENU},
          {"&Back", 0, Form::OnMenuItemClick, this},
          {"&Forward", 0, Form::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"&Show", 0, Form::OnMenuItemClick, this},
          {"&Hide", 0, Form::OnMenuItemClick, this},
          {0},
        {"&Options", 0, nullptr, nullptr, FL_SUBMENU},
          {"Option &A", FL_ALT + '1', Form::OnMenuItemClick, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
          {"Option &B", FL_ALT + '2', Form::OnMenuItemClick, this, FL_MENU_TOGGLE},
          {"Option &C", FL_ALT + '3', Form::OnMenuItemClick, this, FL_MENU_TOGGLE + FL_MENU_CHECK + FL_MENU_DIVIDER},
          {"Option &D", FL_ALT + '4', Form::OnMenuItemClick, this, FL_MENU_RADIO},
          {"Option &E", FL_ALT + '5', Form::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_CHECK},
          {"Option &F", FL_ALT + '6', Form::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_DIVIDER},
          {"Option &G", FL_ALT + '7', Form::OnMenuItemClick, this, FL_MENU_RADIO},
          {"Option &H", FL_ALT + '8', Form::OnMenuItemClick, this, FL_MENU_RADIO},
          {"Option &I", FL_ALT + '9', Form::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_CHECK},
          {0},
        {"&Help", 0, nullptr, nullptr, FL_SUBMENU},
          {"Context", 0, Form::OnMenuItemClick, this},
          {"Index", 0, Form::OnMenuItemClick, this},
          {"Search", 0, Form::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"About", 0, Form::OnMenuItemClick, this},
          {0},
        {0}
      };
      
      contextMenu.type(Fl_Menu_Button::POPUP3);
      contextMenu.copy(items);
    }
    
  private:
    static void OnMenuItemClick(Fl_Widget* sender, void* form) {reinterpret_cast<Form*>(form)->OnMenuItemClick(dynamic_cast<Fl_Menu_Button&>(*sender));}
    void OnMenuItemClick(Fl_Menu_Button& menu) {
      textBuffer.append(menu.mvalue()->label());
      textBuffer.append("\n");
      textBuffer.select(textBuffer.length(), textBuffer.length());
      textDisplay1.show_insert_position();
      menu.value(0);
    }
    Fl_Text_Buffer textBuffer;
    Fl_Text_Display textDisplay1 {0, 0, 300, 300};
    Fl_Menu_Button contextMenu {0, 0, 300, 300, nullptr};
  };
}

int main(int argc, char *argv[]) {
  Examples::Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
