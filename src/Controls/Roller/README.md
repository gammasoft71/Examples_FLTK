# Roller

Shows how to create rollers (horizontal and vertical) with Fl_Roller valuator.

## Source

[Roller.cpp](Roller.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Roller.sln
```

Select Roller project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Roller.xcodeproj
```

Select Roller project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Roller
```
