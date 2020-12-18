cmake_minimum_required(VERSION 3.0)

# Solution
project(Check_Box)
find_package(FLTK REQUIRED)

# Options
if (MSVC)
  set(GUI_OPTION WIN32)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
endif ()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Application
add_executable(${PROJECT_NAME} ${GUI_OPTION} Check_Box.cpp Fl_Check_Box.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "User_Controls")
