# Message_Box

Shows how to use message box with own [fl_message](https://www.fltk.org/doc-1.3/group__group__comdlg.html#ga570c50cf7641b7d85f949b6d61f51c43) method.

## Source

[Dialog_Result.h](Dialog_Result.h)

[fl_message_box.h](fl_message_box.h)

[Message_Box_Buttons.h](Message_Box_Buttons.h)

[Message_Box_Icon.h](Message_Box_Icon.h)

[Message_Box.cpp](Message_Box.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Message_Box.png)

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
