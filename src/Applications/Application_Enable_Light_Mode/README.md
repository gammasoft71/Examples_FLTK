# Application_Enable_Light_Mode

Shows how to create a simple Fltk application with light mode.

## Source

[Application_Enable_Light_Mode.cpp](Application_Enable_Light_Mode.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Application_Enable_Light_Mode.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Application_Enable_Light_Mode.sln
```

Select Application_Enable_Light_Mode project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Application_Enable_Light_Mode.xcodeproj
```

Select Application_Enable_Light_Mode project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Application_Enable_Light_Mode
```
