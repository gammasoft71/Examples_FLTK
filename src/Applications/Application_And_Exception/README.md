# Application_And_Exception

Shows how to create a simple [FLTK](https://www.fltk.org) application and how to manage exception.

## Source

[Application_And_Exception.cpp](Application_And_Exception.cpp)

[Fl_Application.h](Fl_Application.h)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Application_And_Exception.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Application_And_Exception.sln
```

Select Application_And_Exception project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Application_And_Exception.xcodeproj
```

Select Application_And_Exception project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Application_And_Exception
```
