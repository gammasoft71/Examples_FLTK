cmake_minimum_required(VERSION 3.0)

# Solution
project(Radio_Toggle_Button)
find_package(FLTK REQUIRED)

#  Options
if (MSVC)
  set(GUI_OPTION WIN32)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
endif ()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Solution
add_executable(${PROJECT_NAME} ${GUI_OPTION} Radio_Toggle_Button.cpp Fl_Radio_Toggle_Button.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "User_Controls")
