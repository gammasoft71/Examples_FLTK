
# FLTK examples

Shows how to use [FLTK](https://www.fltk.org) controls only by programming code ([c++17](https://en.cppreference.com/w/)).

[![fltk](docs/Pictures/fltk_header.png)](https://www.fltk.org)

## FLTK
* [Hello Worlds](src/Hello_Worlds/README.md) contains [FLTK](https://www.fltk.org) "Hello, World!" examples.
* [Applications](src/Applications/README.md) contains applications examples.
* [Dialogs](src/Dialogs/README.md) contains dialogs examples.
* [Windows](src/Windows/README.md) contains windows examples.
* [Menus and toolbars](src/Menus_And_Toolbars/README.md) contains menus and toolbars examples.
* [Containers](src/Containers/README.md) contains containers examples.
* [Controls](src/Controls/README.md) contains controls examples.
* [Components](src/Components/README.md) contains components examples.
* [Events](src/Events/README.md) contains events examples.
* [Tips And Tricks](src/Tips_And_Tricks/README.md) contains tips and tricks examples.
* [User Dialogs](src/User_Dialogs/README.md) contains user dialogs examples.
* [User Controls](src/User_Controls/README.md) contains user controls examples.
* [User Components](src/User_Components/README.md) contains user componants examples.
* [Others](src/Others/README.md) contains others examples.
* [All](src/README.md) contains all examples

## Download

``` shell
git clone https://github.com/gammasoft71/Examples_FLTK Examples_FLTK
```

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Fltk_Examples.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Fltk_Examples.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Any_Project
```

## Remarks

This project run with [FLTK 1.3.5](https://www.fltk.org) and [CMake](https://cmake.org).
