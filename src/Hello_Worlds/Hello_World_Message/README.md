# Hello_World_Message

The classic first application "Hello World" with [fl_message](https://www.fltk.org/doc-1.3/group__group__comdlg.html#ga570c50cf7641b7d85f949b6d61f51c43).

## Source

[Hello_World_Message.cpp](Hello_World_Message.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Hello_World_Message.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Hello_World_Message.sln
```

Select Hello_World_Message project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Hello_World_Message.xcodeproj
```

Select Hello_World_Message project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Hello_World_Message
```
