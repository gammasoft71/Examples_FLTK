# Colored_Browser

Shows how to create a browser and colored items with Fl_Browser.

## Source

[Colored_Browser.cpp](Colored_Browser.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Colored_Browser.sln
```

Select Colored_Browser project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Colored_Browser.xcodeproj
```

Select Colored_Browser project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Colored_Browser
```
