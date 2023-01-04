# Hello_World_Drawing

The classic first application "Hello World" with GDI+ drawing objects.

## Source

[Hello_World_Drawing.cpp](Hello_World_Drawing.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Hello_World_Drawing.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Hello_World_Drawing.sln
```

Select Hello_World_Drawing project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Hello_World_Drawing.xcodeproj
```

Select Hello_World_Drawing project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Hello_World_Drawing
```
