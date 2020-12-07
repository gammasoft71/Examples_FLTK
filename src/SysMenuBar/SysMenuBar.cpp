#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "SysMenuBar example") {
      resizable(textDisplay1);

      textDisplay1.buffer(&textBuffer);
      textDisplay1.show_cursor(0);

      sysMenuBar.add("&File/&New", FL_COMMAND + 'n', Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&File/&Open", FL_COMMAND + 'o', Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&File/Open &recent/File 1", nullptr, Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&File/Open &recent/File 2", nullptr, Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&File/Open &recent/File 3", nullptr, Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&File/Open &recent/File 4", nullptr, Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&File/Open &recent/File 5", nullptr, Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&File/&Close", FL_COMMAND + 'w', Main_Window::OnMenuItemClick, this, FL_MENU_DIVIDER);
      sysMenuBar.add("&File/&Save", FL_COMMAND + 's', Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&File/Save &as", nullptr, Main_Window::OnMenuItemClick, this, FL_MENU_DIVIDER);
      sysMenuBar.add("&File/Page setup...", FL_COMMAND + FL_SHIFT + 'p', Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&File/&Print", FL_COMMAND + 'p', Main_Window::OnMenuItemClick, this, FL_MENU_DIVIDER);
#if !__APPLE__
      sysMenuBar.add("&File/&Quit", FL_COMMAND + 'q', Main_Window::OnMenuItemClick, this);
#endif
      sysMenuBar.add("&Edit/&Undo", FL_COMMAND + 'z', Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&Edit/&Redo", FL_COMMAND + FL_SHIFT + 'z', Main_Window::OnMenuItemClick, this, FL_MENU_DIVIDER);
      sysMenuBar.add("&Edit/C&ut", FL_COMMAND + 'x', Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&Edit/&Copy", FL_COMMAND + 'c', Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&Edit/&Paste", FL_COMMAND + 'v', Main_Window::OnMenuItemClick, this, FL_MENU_DIVIDER);
      sysMenuBar.add("&Edit/Select &all", FL_COMMAND + 'a', Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&View/&Back", nullptr, Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&View/&Forward", nullptr, Main_Window::OnMenuItemClick, this, FL_MENU_DIVIDER);
      sysMenuBar.add("&View/&Show", nullptr, Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&View/&Hide", nullptr, Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&Options/Option &A", FL_ALT + '1', Main_Window::OnMenuItemClick, this, FL_MENU_TOGGLE + FL_MENU_CHECK);
      sysMenuBar.add("&Options/Option &B", FL_ALT + '2', Main_Window::OnMenuItemClick, this, FL_MENU_TOGGLE);
      sysMenuBar.add("&Options/Option &C", FL_ALT + '3', Main_Window::OnMenuItemClick, this, FL_MENU_TOGGLE + FL_MENU_CHECK + FL_MENU_DIVIDER);
      sysMenuBar.add("&Options/Option &D", FL_ALT + '4', Main_Window::OnMenuItemClick, this, FL_MENU_RADIO);
      sysMenuBar.add("&Options/Option &E", FL_ALT + '5', Main_Window::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_CHECK);
      sysMenuBar.add("&Options/Option &F", FL_ALT + '6', Main_Window::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_DIVIDER);
      sysMenuBar.add("&Options/Option &G", FL_ALT + '7', Main_Window::OnMenuItemClick, this, FL_MENU_RADIO);
      sysMenuBar.add("&Options/Option &H", FL_ALT + '8', Main_Window::OnMenuItemClick, this, FL_MENU_RADIO);
      sysMenuBar.add("&Options/Option &I", FL_ALT + '9', Main_Window::OnMenuItemClick, this, FL_MENU_RADIO + FL_MENU_CHECK);
      sysMenuBar.add("&Help/Context",nullptr, Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&Help/Index",nullptr, Main_Window::OnMenuItemClick, this);
      sysMenuBar.add("&Help/Search",nullptr, Main_Window::OnMenuItemClick, this, FL_MENU_DIVIDER);
#if !__APPLE__
      sysMenuBar.add("&Help/About",nullptr, Main_Window::OnMenuItemClick, this);
#endif
    }
    
  private:
    static void OnMenuItemClick(Fl_Widget* sender, void* window) {reinterpret_cast<Main_Window*>(window)->OnMenuItemClick(dynamic_cast<Fl_Sys_Menu_Bar&>(*sender));}
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
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
