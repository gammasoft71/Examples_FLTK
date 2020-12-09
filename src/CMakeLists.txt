cmake_minimum_required(VERSION 3.0)
project(src)

add_subdirectory(Hello_Worlds)
add_subdirectory(Applications)
add_subdirectory(Common_Controls)
add_subdirectory(User_Controls)
add_subdirectory(Control_Containers)
add_subdirectory(Common_Dialogs)
add_subdirectory(User_Dialogs)
add_subdirectory(Components)
add_subdirectory(Events)
add_subdirectory(Others)

# Containers
add_subdirectory(GroupBox)
add_subdirectory(Panel)
add_subdirectory(TabControl)

# Menus and Toolbars
add_subdirectory(ContextMenu)
add_subdirectory(MenuBar)
add_subdirectory(SysMenuBar)

# Components
add_subdirectory(Timer)

# Dialogs
add_subdirectory(MessageBox)
add_subdirectory(SaveFileDialog)

# Other
add_subdirectory(ColoredForms)
add_subdirectory(ColoredTabPages)
#add_subdirectory(Drawing)
add_subdirectory(GroupBoxAndCheckBox)
add_subdirectory(GroupBoxAndRadioButton)

# Tests
add_subdirectory(TestGui)

