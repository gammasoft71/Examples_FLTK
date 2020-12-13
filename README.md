
# Fltk Examples

Shows how to use Fltk controls only by programming code (c++17).

## [Hello World](src/Hello_Worlds)

* [Hello_World_Box](src/Hello_Worlds/Hello_World_Box) The classic first application "Hello, World!" with Fl_Box.
* [Hello_World_Drawing](src/Hello_Worlds/Hello_World_Drawing) The classic first application "Hello, World!" with GDI+ drawing objects.
* [Hello_World_Emoticons](src/Hello_Worlds/Hello_World_Emoticons) The classic first application "Hello, World!" with Fl_Box and emoticons.
* [Hello_World_Fltk](src/Hello_Worlds/Hello_World_Fltk) The classic first application "Hello, World!" by FLTK.
* [Hello_World_Message](src/Hello_Worlds/Hello_World_Message) The classic first application "Hello, World!" with Fl_Message.
* [Hello_World_Message2](src/Hello_Worlds/Hello_World_Message2) The classic first application "Hello, World!" with Fl_Message.
* [Hello_World_Say](src/Hello_Worlds/Hello_World_Say) The classic first application "Hello, World!" with say.

## [Applications](src/Applications)

* [Application](src/Applications/Application) Shows how to create a simple Fltk application.
* [Application_And_Exception](src/Applications/Application_And_Exception) Shows how to create a simple Fltk application and how to manage exception.
* [Application_Dark_Mode](src/Applications/Application_Dark_Mode) Shows how to create a simple Fltk application with dark mode.

## [Common Controls](src/Common_Controls)

* [Box](src/Common_Controls/Box) Shows how to show a text with Fl_Box widget.
* [Box_Picture](src/Common_Controls/Box_Picture) Shows how to show an image with Fl_Box widget.
* [Browser](src/Common_Controls/Browser) Shows how to create a text list with Fl_Browser widget.
* [Button](src/Common_Controls/Button) Shows how to create a button with Fl_Button widget.
* [Check_Browser](src/Common_Controls/Check_Browser) Shows how to create a check button list with Fl_Check_Browser widget.
* [Check_Button](src/Common_Controls/Check_Button) Shows how to create a check button with Fl_Check_Button widget.
* [Input](src/Common_Controls/Input) Shows how to create an input text with Fl_Input widget.
* [Nice_Slider](src/Common_Controls/Nice_Slider) Shows how to create a slider with Fl_Nice_Slider widget.
* [Progress](src/Common_Controls/Progress) Shows how to create a progress with Fl_Progress widget.
* [Radio_Round_Button](src/Common_Controls/Radio_Round_Button) Shows how to create a radio round button with Fl_Radio_Round_Button widget.
* [Spinner](src/Common_Controls/Spinner) Shows how to create a spinner with Fl_Spinner widget.
* [Toggle_Button](src/Common_Controls/Toggle_Button) Shows how to create a toggle button with Fl_Toggle_Button widget.

## [User Controls](src/User_Controls)

* [Check_Box](src/User_Controls/Check_Box) Shows how to create a check box with own Fl_Check_Box widget.
* [Progress_Bar](src/User_Controls/Progress_Bar) Shows how to create a progress bar with own Fl_Progress_Bar widget.
* [Radio_Toggle_Button](src/User_Controls/Radio_Toggle_Button) Shows how to create a radio button with own Fl_Radio_Toggle_Button widget.

## [Valuators](src/Valuators)

* [Adjuster](src/Valuators/Adjuster) Shows how to create adjusters with Fl_Adjuster valuator.
* [Counter](src/Valuators/Counter) Shows how to create counters with Fl_Counter and Fl_Simple_Counter valuators.
* [Dial](src/Valuators/Dial) Shows how to create dials with Fl_Dial, Fl_Line_Dial and Fl_Fill_Dial valuators.
* [Roller](src/Valuators/Roller) Shows how to create rollers (horizontal and vertical) with Fl_Roller valuator.
* [Slider](src/Valuators/Slider) Shows how to create sliders with Fl_Hor_Slider, Fl_Hor_Fill_Slider, Fl_Hor_Nice_Slider, Fl_Slider, Fl_Fill_Slider and Fl_Nice_Slider valuators.
* [Value_Input](src/Valuators/Value_Input) Shows how to create a value input with Fl_Value_Input valuator.
* [Value_Output](src/Valuators/Value_Output) Shows how to create a value input with Fl_Value_Output valuator.
* [Value_Slider](src/Valuators/Slider) Shows how to create value sliders with Fl_Hor_Value_Slider and Fl_Value_Slider valuators.

## [Control Containers](src/Control_Containers)

* [Group](src/Control_Containers/Group) Shows how to create a group with Fl_Group.
* [Scroll](src/Control_Containers/Scroll) Shows how to create a scroll with Fl_Scroll.
* [Tabs](src/Control_Containers/Tabs) Shows how to create a tabs and pages with Fl_Tabs and Fl_Group.
* [Window](src/Control_Containers/Window) Shows how to create a simple window with Fl_Window.

## Menus and toolbars

* [MainMenu](src/MainMenu) Shows how to create a Fltk MainMenu with Gtk::MenuBar, Gtk::Menu and Gtk::MenuItem.

## Components

* [Timer](src/Timer) Shows how to create a simple Fltk Timer with TimerGtk.

## Dialogs

* [ColorDialog](src/ColorDialog) Shows how to create a ColorDialog with Gtk::ColorChooserDialog.
* [FolderBrowserDialog](src/FolderBrowserDialog) Shows how to create a FolderBrowserDialog with Gtk::FileChooserDialog.
* [FontDialog](src/FontDialog) Shows how to create a FontDialog with Gtk::FontChooserDialog.
* [OpenFileDialog](src/OpenFileDialog) Shows how to create an OpenFileDialog with Gtk::FileChooserDialog.
* [MessageBox](src/MessageBox) Shows how to create a MessageBox with Gtk::MessageDialog.
* [SaveFileDialog](src/SaveFileDialog) Shows how to create an SaveFileDialog with Gtk::FileChooserDialog.

## [Others](src/Others)

* [ComboBox](src/Others/ComboBox) Shows how to create a Fltk ComboBox with Fl_Input_Choice.

## Download

``` shell
git clone https://github.com/gammasoft71/Examples_FLTK Examples_FLTK
```

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` cmake
mkdir build
cd build
cmake .. 
start Fltk_Examples.sln
```

### macOS :

``` cmake
mkdir build
cd build
cmake .. -G "Xcode"
open ./Fltk_Examples.xcodeproj
```


### Linux :

``` cmake
mkdir build
cd build
cmake .. 
cmake --build . --config Debug
```

## Remarks

This project run with [Fltk 1.3.5](https://www.Fltk.org) and [CMake](https://cmake.org).
