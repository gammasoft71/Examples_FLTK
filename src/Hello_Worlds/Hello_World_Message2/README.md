# Hello_World_Message2

The classic first application "Hello World" with Fl_Message.

## Source

[Hello_World_Message2.cpp](Hello_World_Message2.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Hello_World_Message2.sln
```

Select Hello_World_Message2 project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Hello_World_Message2.xcodeproj
```

Select Hello_World_Message2 project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Hello_World_Message2
```
