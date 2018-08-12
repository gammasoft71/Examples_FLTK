cmake_minimum_required(VERSION 3.5)

project(PictureBox VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
  set(GUI_OPTION WIN32)
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
elseif(UNIX)
  set(GUI_OPTION )
endif ()

find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Resources/Logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/Resources/Logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release/Resources/Logo.png COPYONLY)

add_executable(PictureBox ${GUI_OPTION} PictureBox.cpp)
target_link_libraries(PictureBox ${FLTK_LIBRARIES})
