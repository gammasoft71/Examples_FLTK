# Message_Box

Shows how to use message box with own fl_message_box method.

## Source

[Message_Box.cpp](Message_Box.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Message_Box.sln
```

Select Message_Box project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Message_Box.xcodeproj
```

Select Message_Box project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Message_Box
```
