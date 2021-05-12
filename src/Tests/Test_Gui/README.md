# Test_Gui

is used to experiment test

## Source

[Test_Gui.cpp](Test_Gui.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Test_Gui.sln
```

Select Test_Gui project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Test_Gui.xcodeproj
```

Select Test_Gui project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Test_Gui
```
