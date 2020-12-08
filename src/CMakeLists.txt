cmake_minimum_required(VERSION 3.0)
project(src)

add_subdirectory(Hello_Worlds)
add_subdirectory(Applications)
add_subdirectory(Common_Controls)
add_subdirectory(User_Controls)
add_subdirectory(Components)
add_subdirectory(Events)
add_subdirectory(Others)

# Common Controls
add_subdirectory(ListBox)
add_subdirectory(ProgressBar)
add_subdirectory(PictureBox)
add_subdirectory(RadioButton)
add_subdirectory(TextBox)
add_subdirectory(ToggleButton)
add_subdirectory(TrackBar)

# Containers
add_subdirectory(Form)
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
add_subdirectory(ColorDialog)
add_subdirectory(FolderBrowserDialog)
add_subdirectory(FontDialog)
add_subdirectory(OpenFileDialog)
add_subdirectory(OpenFileDialog2)
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
