cmake_minimum_required(VERSION 3.0)
project(Color_Chooser)

find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
link_libraries(${FLTK_LIBRARIES})

if (MSVC)
  set(GUI_OPTION WIN32)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} ${GUI_OPTION} Color_Chooser.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Common_Dialogs")
