# Timer

Shows how to create a timer with Fl::add_timeout, Fl::remove_timeout and Fl::repeat_timeout methods.

## Source

[Timer.cpp](Timer.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Timer.sln
```

Select Timer project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Timer.xcodeproj
```

Select Timer project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Timer
```
