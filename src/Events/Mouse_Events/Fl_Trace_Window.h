#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Window.H>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

class Fl_Trace_Window : public Fl_Window {
public:
  Fl_Trace_Window() : Fl_Window {0, 0, "Debug"} {
    resizable(this);
    auto screen_num = Fl::screen_num(x(), y());
    auto screen_x = 0, screen_y = 0, screen_width = 0, screen_height = 0;
    Fl::screen_xywh(screen_x, screen_y, screen_width, screen_height);
    resize(screen_x, screen_y + (screen_height / 5 * 4), screen_width, screen_height / 5);
    text_display.buffer(&text_buffer);
#if defined(TRACE)
    show();
#endif
  }
  
  void append(const char* value) noexcept {
#if defined(TRACE)
    if (need_header) write_header();
    text_buffer.append(value);
    std::cerr << value;
    text_display.scroll(text_buffer.count_lines(0, text_buffer.length()), 0);
#endif
  }
  
  void append_line(const char* value) noexcept {
#if defined(TRACE)
    if (need_header) write_header();
    text_buffer.append(value);
    std::cerr << value;
    text_buffer.append("\n");
    std::cerr << std::endl;
    text_display.scroll(text_buffer.count_lines(0, text_buffer.length()), 0);
    need_header = true;
#endif
  }
  
  void hide() noexcept override {iconize();}
  
  void resize(int x, int y, int width, int height) noexcept override {
    Fl_Window::resize(x, y, width, height);
    text_display.resize(0, 0, w(), h());
  }
  
private:
  void write_header() noexcept {
    auto current_time = time(nullptr);
    auto current_tm = localtime(&current_time);
    auto ss = std::stringstream {};
    ss << std::put_time(current_tm, "%Y-%m-%d %H:%M:%S - ");
    text_buffer.append(ss.str().c_str());
    std::cerr << ss.str();
    need_header = false;
  }
  
  bool need_header = true;
  Fl_Text_Buffer text_buffer;
  Fl_Text_Display text_display {0, 0, 0, 0};
};
