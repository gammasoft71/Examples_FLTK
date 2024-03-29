# File_Chooser_Browse_Directory

Shows how to use file chooser browse directory with [fl_dir_chooser](https://www.fltk.org/doc-1.3/group__group__comdlg.html#ga24f703a97e90934198a474d19b22732dl)  method.

## Source

[File_Chooser_Browse_Directory.cpp](File_Chooser_Browse_Directory.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/File_Chooser_Browse_Directory.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start File_Chooser_Browse_Directory.sln
```

Select File_Chooser_Browse_Directory project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./File_Chooser_Browse_Directory.xcodeproj
```

Select File_Chooser_Browse_Directory project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./File_Chooser_Browse_Directory
```
