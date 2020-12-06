#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class MainWindow : public Fl_Window {
  public:
    MainWindow() : Fl_Window(200, 100, 300, 300, "MenuBar example") {
      resizable(textDisplay1);

      textDisplay1.buffer(&textBuffer);
      textDisplay1.show_cursor(0);

      Fl_Menu_Item items[] = {
        {"&File", 0, nullptr, nullptr, FL_SUBMENU},
          {"&New", FL_COMMAND + 'n', &MainWindow::OnMenuItemClick, this},
          {"&Open", FL_COMMAND + 'o', &MainWindow::OnMenuItemClick, this},
          {"Open &recent", 0, nullptr, nullptr, FL_SUBMENU},
            {"File 1", 0, &MainWindow::OnMenuItemClick, this},
            {"File 2", 0, &MainWindow::OnMenuItemClick, this},
            {"File 3", 0, &MainWindow::OnMenuItemClick, this},
            {"File 4", 0, &MainWindow::OnMenuItemClick, this},
            {"File 5", 0, &MainWindow::OnMenuItemClick, this},
            {0},
          {"&Close", FL_COMMAND + 'w', &MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"&Save", FL_COMMAND + 's', &MainWindow::OnMenuItemClick, this},
          {"Save &as...", 0, &MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"Page setup...", FL_COMMAND + FL_SHIFT + 'p', &MainWindow::OnMenuItemClick, this},
          {"&Print", FL_COMMAND + 'p', &MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"&Quit", FL_COMMAND + 'q', &MainWindow::OnMenuItemClick, this},
          {0},
        {"&Edit", 0, nullptr, nullptr, FL_SUBMENU},
          {"&Undo", FL_COMMAND + 'z', &MainWindow::OnMenuItemClick, this},
          {"&Redo", FL_COMMAND + FL_SHIFT + 'z', &MainWindow::OnMenuItemClick, this},
          {"C&ut", FL_COMMAND + 'x', MainWindow::OnMenuItemClick, this},
          {"&Copy", FL_COMMAND + 'c', MainWindow::OnMenuItemClick, this},
          {"&Paste", FL_COMMAND + 'v', MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"Select &all", FL_COMMAND + 'a', MainWindow::OnMenuItemClick, this},
          {0},
        {"&View", 0, nullptr, nullptr, FL_SUBMENU},
          {"&Back", 0, MainWindow::OnMenuItemClick, this},
          {"&Forward", 0, MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"&Show", 0, MainWindow::OnMenuItemClick, this},
          {"&Hide", 0, MainWindow::OnMenuItemClick, this},
          {0},
        {"&Options", 0, nullptr, nullptr, FL_SUBMENU},
          {"Option &A", FL_ALT + '1', MainWindow::OnMenuItemClick, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
          {"Option &B", FL_ALT + '2', MainWindow::OnMenuItemClick, this, FL_MENU_TOGGLE},
          {"Option &C", FL_ALT + '3', MainWindow::OnMenuItemClick, this, FL_MENU_TOGGLE + FL_MENU_CHECK + FL_MENU_DIVIDER},
          {"Option &D", FL_ALT + '4', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO},
          {"Option &E", FL_ALT + '5', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_CHECK},
          {"Option &F", FL_ALT + '6', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_DIVIDER},
          {"Option &G", FL_ALT + '7', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO},
          {"Option &H", FL_ALT + '8', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO},
          {"Option &I", FL_ALT + '9', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_CHECK},
          {0},
        {"&Help", 0, nullptr, nullptr, FL_SUBMENU},
          {"Context", 0, MainWindow::OnMenuItemClick, this},
          {"Index", 0, MainWindow::OnMenuItemClick, this},
          {"Search", 0, MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER},
          {"About", 0, MainWindow::OnMenuItemClick, this},
          {0},
        {0}
      };
      
      menuBar.copy(items);
      menuBar.parent(this);
    }
    
  private:
    static void OnMenuItemClick(Fl_Widget* sender, void* window) {reinterpret_cast<MainWindow*>(window)->OnMenuItemClick(dynamic_cast<Fl_Menu_Bar&>(*sender));}
    void OnMenuItemClick(Fl_Menu_Bar& menu) {
      textBuffer.append(menu.mvalue()->label());
      textBuffer.append("\n");
      textBuffer.select(textBuffer.length(), textBuffer.length());
      textDisplay1.show_insert_position();
      menu.value(0);
    }
    Fl_Text_Buffer textBuffer;
    Fl_Menu_Bar menuBar {0, 0, 300, 30, nullptr};
    Fl_Text_Display textDisplay1 {0, 30, 300, 270};
  };
}

int main(int argc, char *argv[]) {
  Examples::MainWindow window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
