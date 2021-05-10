# Hello_World_Say

The classic first application "Hello World" with say.

## Source

[Hello_World_Say.cpp](Hello_World_Say.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Hello_World_Say.sln
```

Select Hello_World_Say project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Hello_World_Say.xcodeproj
```

Select Hello_World_Say project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Hello_World_Say
```
