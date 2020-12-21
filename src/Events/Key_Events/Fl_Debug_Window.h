#pragma once
#include <ctime>
#include <iomanip>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Window.H>

class Fl_Debug_Window : public Fl_Window {
public:
  Fl_Debug_Window() : Fl_Window(0, 0, "Debug") {
    resizable(this);
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
  
  void resize(int x, int y, int width, int height) override {
    Fl_Window::resize(x, y, width, height);
    text_display.resize(0, 0, w(), h());
  }
  
private:
  void write_header() {
    auto current_time = time(nullptr);
    auto current_tm = localtime(&current_time);
    std::stringstream ss;
    ss << std::put_time(current_tm, "%Y-%m-%d %H:%M:%S - ");
    text_buffer.append(ss.str().c_str());
    need_header = false;
  }
  
  bool need_header = true;
  Fl_Text_Buffer text_buffer;
  Fl_Text_Display text_display {0, 0, 0, 0};
};
