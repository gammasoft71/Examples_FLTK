cmake_minimum_required(VERSION 3.0)
project(FolderBrowserDialog)

find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
link_libraries(${FLTK_LIBRARIES})

if (MSVC)
  set(GUI_OPTION WIN32)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
endif ()

add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(FolderBrowserDialog ${GUI_OPTION} FolderBrowserDialog.cpp)
