#pragma once

#include "Dialog_Result.h"
#include "Message_Box_Buttons.h"
#include "Message_Box_Icon.h"
#include <array>
#include <map>
#include <string>
#include <FL/Fl_Widget.H>
#include <FL/fl_message.H>

inline Dialog_Result fl_message_box(const std::string& message, const std::string& title, Message_Box_Buttons buttons, Message_Box_Icon icon) {
  using namespace std;
  using namespace std::literals;
  
  struct Message_Params {
    Message_Params() = default;
    ~Message_Params() {
      fl_message_hotspot(hotspot);
      fl_message_icon()->box(box);
      fl_message_icon()->color(color);
      fl_message_icon()->label(label);
      fl_message_icon()->labelcolor(labelcolor);
      fl_message_icon()->labelfont(labelfont);
      fl_message_icon()->show();
      fl_message_title("");
    }

    int hotspot =  fl_message_hotspot();
    Fl_Boxtype box = fl_message_icon()->box();
    Fl_Color color = fl_message_icon()->color();
    Fl_Color labelcolor = fl_message_icon()->labelcolor();
    Fl_Font labelfont = fl_message_icon()->labelfont();
    const char* label = fl_message_icon()->label();
  } message_params;
  
  static map<Message_Box_Icon, Fl_Boxtype> box_Types = {{Message_Box_Icon::None, FL_NO_BOX}, {Message_Box_Icon::Hand, FL_ROUND_UP_BOX}, {Message_Box_Icon::Question, FL_ROUND_UP_BOX}, {Message_Box_Icon::Exclamation, FL_DIAMOND_UP_BOX}, {Message_Box_Icon::Asterisk, FL_ROUND_UP_BOX}};
  static map<Message_Box_Icon, Fl_Color> colors = {{Message_Box_Icon::None, fl_rgb_color(255, 255, 255)}, {Message_Box_Icon::Hand, fl_rgb_color(255, 0, 0)}, {Message_Box_Icon::Question, fl_rgb_color(0, 0, 255)}, {Message_Box_Icon::Exclamation, fl_rgb_color(255, 255, 0)}, {Message_Box_Icon::Asterisk, fl_rgb_color(0, 0, 255)}};
  static map<Message_Box_Icon, Fl_Color> label_Colors = {{Message_Box_Icon::None, fl_rgb_color(0, 0, 255)}, {Message_Box_Icon::Hand, fl_rgb_color(255, 255, 255)}, {Message_Box_Icon::Question, fl_rgb_color(255, 255, 255)}, {Message_Box_Icon::Exclamation, fl_rgb_color(0, 0, 0)}, {Message_Box_Icon::Asterisk, fl_rgb_color(255, 255, 255)}};
  static map<Message_Box_Icon, string> labels = {{Message_Box_Icon::None, ""}, {Message_Box_Icon::Hand, "X"}, {Message_Box_Icon::Question, "?"}, {Message_Box_Icon::Exclamation, "!"}, {Message_Box_Icon::Asterisk, "i"}};
  static map<Message_Box_Buttons, array<const char*, 3>> message_Box_Buttons_Texts {{Message_Box_Buttons::Ok, {nullptr, "&OK", nullptr}}, {Message_Box_Buttons::Ok_Cancel, {"&Cancel", "&OK", nullptr}}, {Message_Box_Buttons::Abort_Retry_Ignore, {"&Abort", "&Retry", "&Ignore"}}, {Message_Box_Buttons::Yes_No_Cancel, {"&Cancel", "&Yes", "&No"}}, {Message_Box_Buttons::Yes_No, {"&No", "&Yes", nullptr}}, {Message_Box_Buttons::Retry_Cancel, {"&Cancel", "&Retry", nullptr}}};
  static map<Message_Box_Buttons, array<Dialog_Result, 3>> message_Box_Buttons_Results {{Message_Box_Buttons::Ok, {Dialog_Result::Ok, Dialog_Result::Ok, Dialog_Result::Ok}}, {Message_Box_Buttons::Ok_Cancel, {Dialog_Result::Cancel, Dialog_Result::Ok, Dialog_Result::None}}, {Message_Box_Buttons::Abort_Retry_Ignore, {Dialog_Result::Abort, Dialog_Result::Retry, Dialog_Result::Ignore}}, {Message_Box_Buttons::Yes_No_Cancel, {Dialog_Result::Cancel, Dialog_Result::Yes, Dialog_Result::No}}, {Message_Box_Buttons::Yes_No, {Dialog_Result::No, Dialog_Result::Yes, Dialog_Result::None}}, {Message_Box_Buttons::Retry_Cancel, {Dialog_Result::Cancel, Dialog_Result::Retry, Dialog_Result::No}}};
  
  fl_message_icon()->box(box_Types[icon]);
  fl_message_icon()->color(colors[icon]);
  fl_message_icon()->label(labels[icon].c_str());
  fl_message_icon()->labelcolor(label_Colors[icon]);
  fl_message_icon()->labelfont(FL_HELVETICA_BOLD);
  if (icon == Message_Box_Icon::None) fl_message_icon()->hide();
  fl_message_title(title.c_str());
  return  message_Box_Buttons_Results[buttons][fl_choice("%s", message_Box_Buttons_Texts[buttons][0], message_Box_Buttons_Texts[buttons][1], message_Box_Buttons_Texts[buttons][2], message.c_str())];
}

inline Dialog_Result fl_message_box(const std::string& message, const std::string& title, Message_Box_Buttons buttons) {return fl_message_box(message, title, buttons, Message_Box_Icon::None);}
inline Dialog_Result fl_message_box(const std::string& message, const std::string& title) {return fl_message_box(message, title, Message_Box_Buttons::Ok);}
inline Dialog_Result fl_message_box(const std::string& message) {return fl_message_box(message, "");}
