# Colored_Tabs

Shows how to create a tabs and colored pages with [Fl_Tabs](https://www.fltk.org/doc-1.3/classFl__Tabs.html) and [Fl_Group](https://www.fltk.org/doc-1.3/classFl__Group.html)..

## Source

[Colored_Tabs.cpp](Colored_Tabs.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Colored_Tabs.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Colored_Tabs.sln
```

Select Colored_Tabs project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Colored_Tabs.xcodeproj
```

Select Colored_Tabs project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Colored_Tabs
```
