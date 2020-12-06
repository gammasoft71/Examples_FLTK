#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class MainWindow : public Fl_Window {
  public:
    MainWindow() : Fl_Window(200, 100, 300, 300, "SysMenuBar example") {
      resizable(textDisplay1);

      textDisplay1.buffer(&textBuffer);
      textDisplay1.show_cursor(0);

      sysMenuBar.add("&File/&New", FL_COMMAND + 'n', MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&File/&Open", FL_COMMAND + 'o', MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&File/Open &recent/File 1", nullptr, MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&File/Open &recent/File 2", nullptr, MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&File/Open &recent/File 3", nullptr, MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&File/Open &recent/File 4", nullptr, MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&File/Open &recent/File 5", nullptr, MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&File/&Close", FL_COMMAND + 'w', MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER);
      sysMenuBar.add("&File/&Save", FL_COMMAND + 's', MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&File/Save &as", nullptr, MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER);
      sysMenuBar.add("&File/Page setup...", FL_COMMAND + FL_SHIFT + 'p', MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&File/&Print", FL_COMMAND + 'p', MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER);
#if !__APPLE__
      sysMenuBar.add("&File/&Quit", FL_COMMAND + 'q', MainWindow::OnMenuItemClick, this);
#endif
      sysMenuBar.add("&Edit/&Undo", FL_COMMAND + 'z', MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&Edit/&Redo", FL_COMMAND + FL_SHIFT + 'z', MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER);
      sysMenuBar.add("&Edit/C&ut", FL_COMMAND + 'x', MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&Edit/&Copy", FL_COMMAND + 'c', MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&Edit/&Paste", FL_COMMAND + 'v', MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER);
      sysMenuBar.add("&Edit/Select &all", FL_COMMAND + 'a', MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&View/&Back", nullptr, MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&View/&Forward", nullptr, MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER);
      sysMenuBar.add("&View/&Show", nullptr, MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&View/&Hide", nullptr, MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&Options/Option &A", FL_ALT + '1', MainWindow::OnMenuItemClick, this, FL_MENU_TOGGLE + FL_MENU_CHECK);
      sysMenuBar.add("&Options/Option &B", FL_ALT + '2', MainWindow::OnMenuItemClick, this, FL_MENU_TOGGLE);
      sysMenuBar.add("&Options/Option &C", FL_ALT + '3', MainWindow::OnMenuItemClick, this, FL_MENU_TOGGLE + FL_MENU_CHECK + FL_MENU_DIVIDER);
      sysMenuBar.add("&Options/Option &D", FL_ALT + '4', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO);
      sysMenuBar.add("&Options/Option &E", FL_ALT + '5', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_CHECK);
      sysMenuBar.add("&Options/Option &F", FL_ALT + '6', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_DIVIDER);
      sysMenuBar.add("&Options/Option &G", FL_ALT + '7', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO);
      sysMenuBar.add("&Options/Option &H", FL_ALT + '8', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO);
      sysMenuBar.add("&Options/Option &I", FL_ALT + '9', MainWindow::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_CHECK);
      sysMenuBar.add("&Help/Context",nullptr, MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&Help/Index",nullptr, MainWindow::OnMenuItemClick, this);
      sysMenuBar.add("&Help/Search",nullptr, MainWindow::OnMenuItemClick, this, FL_MENU_DIVIDER);
#if !__APPLE__
      sysMenuBar.add("&Help/About",nullptr, MainWindow::OnMenuItemClick, this);
#endif
    }
    
  private:
    static void OnMenuItemClick(Fl_Widget* sender, void* window) {reinterpret_cast<MainWindow*>(window)->OnMenuItemClick(dynamic_cast<Fl_Sys_Menu_Bar&>(*sender));}
    void OnMenuItemClick(Fl_Sys_Menu_Bar& menu) {
      textBuffer.append(menu.mvalue()->label());
      textBuffer.append("\n");
      textBuffer.select(textBuffer.length(), textBuffer.length());
      textDisplay1.show_insert_position();
      menu.value(0);
    }
    Fl_Text_Buffer textBuffer;
    Fl_Sys_Menu_Bar sysMenuBar {0, 0, 300, 30, nullptr};
#if __APPLE__
    Fl_Text_Display textDisplay1 {0, 0, 300, 300};
#else
    Fl_Text_Display textDisplay1 {0, 30, 300, 270};
#endif
  };
}

int main(int argc, char *argv[]) {
  Examples::MainWindow window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
