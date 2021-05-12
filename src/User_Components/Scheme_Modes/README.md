# Scheme_Modes

Shows how to use own scheme modes with own fl_scheme_mode methods.

## Source

[Scheme_Modes.cpp](Scheme_Modes.cpp)

[Fl_Scheme_Mode.h](Fl_Scheme_Mode.h)

[Fl_Scheme_Mode.cpp](Fl_Scheme_Mode.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Scheme_Modes.sln
```

Select Scheme_Modes project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Scheme_Modes.xcodeproj
```

Select Scheme_Modes project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Scheme_Modes
```
