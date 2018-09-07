cmake_minimum_required(VERSION 3.0)
project(PictureBox)

find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
link_libraries(${FLTK_LIBRARIES})

if (MSVC)
  set(GUI_OPTION WIN32)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
endif ()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Resources/Logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/Resources/Logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release/Resources/Logo.png COPYONLY)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(PictureBox ${GUI_OPTION} PictureBox.cpp)
