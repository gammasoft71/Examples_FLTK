# Application_Idle

Shows how to use idle event with [Fl::add_idle](https://www.fltk.org/doc-1.3/classFl.html#a4e7a1b5d18c2f073238a8466a62a3e7a) method.

## Source

[Application_Idle.cpp](Application_Idle.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Application_Idle.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Application_Idle.sln
```

Select Application_Idle project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Application_Idle.xcodeproj
```

Select Application_Idle project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Application_Idle
```
