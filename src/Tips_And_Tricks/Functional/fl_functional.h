#pragma onnce
#include <FL/Fl_Widget.H>
#include <tuple>

template<typename fct_t, typename arg_t>
void fl_functional(Fl_Widget& widget, fct_t&& fct, arg_t&& arg) {
  widget.callback([](Fl_Widget* sender, void* data) {
    std::get<0>(*reinterpret_cast<std::tuple<fct_t, arg_t&&>*>(data))(*sender, std::get<1>(*reinterpret_cast<std::tuple<fct_t, arg_t&&>*>(data)));
  }, new std::tuple<fct_t, arg_t>(fct, arg));
}

template<typename fct_t>
void fl_functional(Fl_Widget& widget, fct_t&& fct) {
  widget.callback([](Fl_Widget* sender, void* data) {
    (*reinterpret_cast<fct_t*>(data))(*sender);
  }, new fct_t(fct));
}

template<typename fct_t, typename arg_t>
void fl_functional(Fl_Widget* widget, fct_t&& fct, arg_t&& arg) {
  widget->callback([](Fl_Widget* sender, void* data) {
    std::get<0>(*reinterpret_cast<std::tuple<fct_t&&, arg_t&&>*>(data))(*sender, std::get<1>(*reinterpret_cast<std::tuple<fct_t, arg_t&&>*>(data)));
  }, new std::tuple<fct_t, arg_t>(fct, arg));
}

template<typename fct_t>
void fl_functional(Fl_Widget* widget, fct_t&& fct) {
  widget->callback([](Fl_Widget* sender, void* data) {
    (*reinterpret_cast<fct_t*>(data))(*sender);    
  }, new fct_t(fct));
}
