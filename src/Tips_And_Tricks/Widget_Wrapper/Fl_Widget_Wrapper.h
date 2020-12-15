#pragma once
#include <FL/Fl_Widget.H>
#include <any>
#include <functional>

template<typename widget_t>
class Fl_Widget_Wrapper : public widget_t {
public:
  template<typename ...args_type>
  Fl_Widget_Wrapper(args_type&& ...args) : widget_t(args...) {
    widget_t::callback(on_callback);
  }
  
  template <typename callback_t>
  void callback(callback_t&& callback) {
    callback_ = callback;
  }
  
  template <typename callback_t>
  void callback(callback_t&& callback, std::any arg) {
    callback_ = callback;
    arg_ = arg;
  }
  
private:
  static void on_callback(Fl_Widget* sender, void* data) {
    auto widget = dynamic_cast<Fl_Widget_Wrapper<widget_t>*>(sender);
    widget->callback_(*sender, widget->arg_);
  }
  
  std::function<void(Fl_Widget&, std::any)> callback_;
  std::any arg_;
};
