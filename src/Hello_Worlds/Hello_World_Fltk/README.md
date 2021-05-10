# Hello_World_Fltk

The classic first application "Hello World" by FLTK.

## Source

[Hello_World_Fltk.cpp](Hello_World_Fltk.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Hello_World_Fltk.sln
```

Select Hello_World_Fltk project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Hello_World_Fltk.xcodeproj
```

Select Hello_World_Fltk project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Hello_World_Fltk
```
