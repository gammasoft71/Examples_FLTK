# Hello_World_Box

The classic first application "Hello World".

# Source

[Hello_World_Box.cpp](Hello_World_Box.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Generate and build

To build this project, open "Terminal" and type following lines:

## Windows :

``` cmake
mkdir build
cd build
cmake .. 
start Hello_World_Box.sln
```

## macOS :

``` cmake
mkdir build
cd build
cmake .. -G "Xcode"
open ./Hello_World_Box.xcodeproj
```

## Linux :

``` cmake
mkdir build
cd build
cmake .. 
cmake --build . --config Debug
```
