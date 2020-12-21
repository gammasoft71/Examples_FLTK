#pragma once
#include <ctime>
#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Window.H>

class Fl_Debug_Window : public Fl_Window {
public:
  Fl_Debug_Window() : Fl_Window(200, 100, 300, 300, "Debug") {
    resizable(text_display);
    auto screen_num = Fl::screen_num(x(), y());
    auto screen_x = 0, screen_y = 0, screen_width = 0, screen_height = 0;
    Fl::screen_xywh(screen_x, screen_y, screen_width, screen_height);
    resize(screen_x, screen_y + (screen_height / 5 * 4), screen_width, screen_height / 5);
    text_display.buffer(&text_buffer);
    show();
  }
  
  void append(const char* value) {
    if (need_header) write_header();
    text_buffer.append(value);
    text_display.scroll(text_buffer.count_lines(0, text_buffer.length()), 0);
  }
  
  void append_line(const char* value) {
    if (need_header) write_header();
    text_buffer.append(value);
    text_buffer.append("\n");
    text_display.scroll(text_buffer.count_lines(0, text_buffer.length()), 0);
    need_header = true;
  }
  
  void hide() override {iconize();}
  
private:
  void write_header() {
    time_t curtime = time(NULL);
    struct tm *curdate = localtime(&curtime);
    char date[23];
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S - ", curdate);
    text_buffer.append(date);
    need_header = false;
  }
  
  bool need_header = true;
  Fl_Text_Buffer text_buffer;
  Fl_Text_Display text_display {0, 0, 300, 300};
};
