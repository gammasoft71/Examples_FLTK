#pragma once
#include "Fl_Combo_Box_Style.h"
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Group.H>

// Minimal implementation for example. Needs to be completed
class Fl_Combo_Box : public Fl_Group {
public:
  Fl_Combo_Box(int x, int y, int width, int height, const char* label = nullptr) : Fl_Group {x, y, width, height}, drop_down_ {std::make_unique<Fl_Input_Choice>(x, y, width, 25, label)}, label_ {label} {
    end();
    drop_down_->callback(on_callback, this);
  }
  
  Fl_Combo_Box_Style style() const {return style_;}
  void style(Fl_Combo_Box_Style style) {
    if (style_ != style) {
      style_ = style;
      begin();
      simple_.reset();
      drop_down_.reset();
      drop_down_list_.reset();
      switch (style_) {
        case Fl_Combo_Box_Style::simple: simple_ = std::make_unique<Fl_Choice>(x(), y(), w(), 25, label_); break;
        case Fl_Combo_Box_Style::drop_down: drop_down_ = std::make_unique<Fl_Input_Choice>(x(), y(), w(), 25, label_); break;
        case Fl_Combo_Box_Style::drop_down_list: drop_down_list_ = std::make_unique<Fl_Drop_Down_List>(x(), y(), w(), h(), label_); break;
      }
      end();

      auto items = std::move(items_);
      for (auto item : items)
        add(item.c_str());

      switch (style_) {
        case Fl_Combo_Box_Style::simple: simple_->callback(on_callback, this); break;
        case Fl_Combo_Box_Style::drop_down: drop_down_->callback(on_callback, this); break;
        case Fl_Combo_Box_Style::drop_down_list: drop_down_list_->callback(on_callback, this); break;
      }
    }
  }
  
  const char* value() const {
    switch (style_) {
      case Fl_Combo_Box_Style::simple: return simple_->text(simple_->value()); break;
      case Fl_Combo_Box_Style::drop_down: return drop_down_->value(); break;
      case Fl_Combo_Box_Style::drop_down_list: return drop_down_list_->value(); break;
    }
  }
  
  void value(const char* value) {
    switch (style_) {
      case Fl_Combo_Box_Style::simple: simple_->value(simple_->find_index(value)); break;
      case Fl_Combo_Box_Style::drop_down: drop_down_->value(value); break;
      case Fl_Combo_Box_Style::drop_down_list: drop_down_list_->value(value); break;
    }
  }

  void value(int value) {
    if (value == -1) return;
    switch (style_) {
      case Fl_Combo_Box_Style::simple: simple_->value(value); break;
      case Fl_Combo_Box_Style::drop_down: drop_down_->value(value); break;
      case Fl_Combo_Box_Style::drop_down_list: drop_down_list_->value(value); break;
    }
  }

  void add(const char* item) {
    add(std::string(item));
  }

  void add(const std::string& item) {
    items_.push_back(item);
    switch (style_) {
      case Fl_Combo_Box_Style::simple: simple_->add(items_.at(items_.size() - 1).c_str()); break;
      case Fl_Combo_Box_Style::drop_down: drop_down_->add(items_.at(items_.size() - 1).c_str()); break;
      case Fl_Combo_Box_Style::drop_down_list: drop_down_list_->add(items_.at(items_.size() - 1).c_str()); break;
    }
  }

  template <typename items_t>
  void add_range(items_t&& items) {
    for (auto item : items)
      add(item);
  }
  
  template <typename item_t>
  void add_range(std::initializer_list<item_t> items) {
    for (auto item : items)
      add(item);
  }
  
  template <typename item_t>
  void add_range(const std::vector<item_t>& items) {
    for (auto item : items)
      add(item);
  }

  int find_index(const char* name) const {
    switch (style_) {
      case Fl_Combo_Box_Style::simple: return simple_->find_index(name); break;
      case Fl_Combo_Box_Style::drop_down: return drop_down_->menubutton()->find_index(name); break;
      case Fl_Combo_Box_Style::drop_down_list: return drop_down_list_->find_index(name); break;
    }
  }
  
private:
  class Fl_Drop_Down_List : public Fl_Group {
  public:
    Fl_Drop_Down_List(int x, int y, int width, int height, const char* label) : Fl_Group {x, y, width, height}, input_ {x, y, width, 25, label}, browser_ {x, y + 25, width, height - 25} {
      end();
      when(FL_WHEN_CHANGED);
      browser_.type(FL_HOLD_BROWSER);
      input_.callback(on_input_callback, this);
      browser_.callback(on_browser_callback, this);
    }
    
    const char* value() const {return input_.value();}
    void value(const char* value) {input_.value(value);}
    void value(int value) {
      browser_.value(value + 1);
      input_.value(browser_.text(value + 1));
    }
    
    Fl_When when() const {return Fl_Group::when();}
    void when(uchar when) {
      Fl_Group::when(when);
      input_.when(when);
      browser_.when(when);
    }


    void add(const char *s) {browser_.add(s);}
    
    int find_index(const char* name) const {
      for (int index = 1; index <= browser_.size(); ++index)
        if (browser_.text(index) == std::string(name)) return index - 1;
      return -1;
    }

  private:
    static void on_browser_callback(Fl_Widget* sender, void* data) {
      auto drop_down_list = reinterpret_cast<Fl_Drop_Down_List*>(data);
      drop_down_list->input_.value(drop_down_list->browser_.text(drop_down_list->browser_.value()));
      drop_down_list->do_callback();
    }
    
    static void on_input_callback(Fl_Widget* sender, void* data) {
      auto drop_down_list = reinterpret_cast<Fl_Drop_Down_List*>(data);
      drop_down_list->browser_.value(drop_down_list->find_index(drop_down_list->input_.value()));
      drop_down_list->do_callback();
    }
    
    Fl_Input input_ {0, 0, 100, 25};
    Fl_Browser browser_ {0, 25, 100, 100};
  };
  
  static void on_callback(Fl_Widget* sender, void* data) {reinterpret_cast<Fl_Widget*>(data)->do_callback();}
  
  Fl_Combo_Box_Style style_ = Fl_Combo_Box_Style::drop_down;
  std::unique_ptr<Fl_Choice> simple_;
  std::unique_ptr<Fl_Input_Choice> drop_down_;
  std::unique_ptr<Fl_Drop_Down_List> drop_down_list_;
  const char* label_ = nullptr;
  std::string input_item_;
  std::vector<std::string> items_;
};
