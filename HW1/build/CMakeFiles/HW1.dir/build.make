# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Codefield\DS\HW1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Codefield\DS\HW1\build

# Include any dependencies generated for this target.
include CMakeFiles/HW1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW1.dir/flags.make

CMakeFiles/HW1.dir/HW1.c.obj: CMakeFiles/HW1.dir/flags.make
CMakeFiles/HW1.dir/HW1.c.obj: ../HW1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Codefield\DS\HW1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HW1.dir/HW1.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HW1.dir\HW1.c.obj   -c D:\Codefield\DS\HW1\HW1.c

CMakeFiles/HW1.dir/HW1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW1.dir/HW1.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Codefield\DS\HW1\HW1.c > CMakeFiles\HW1.dir\HW1.c.i

CMakeFiles/HW1.dir/HW1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW1.dir/HW1.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Codefield\DS\HW1\HW1.c -o CMakeFiles\HW1.dir\HW1.c.s

# Object files for target HW1
HW1_OBJECTS = \
"CMakeFiles/HW1.dir/HW1.c.obj"

# External object files for target HW1
HW1_EXTERNAL_OBJECTS =

bin/HW1.exe: CMakeFiles/HW1.dir/HW1.c.obj
bin/HW1.exe: CMakeFiles/HW1.dir/build.make
bin/HW1.exe: CMakeFiles/HW1.dir/linklibs.rsp
bin/HW1.exe: CMakeFiles/HW1.dir/objects1.rsp
bin/HW1.exe: CMakeFiles/HW1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Codefield\DS\HW1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin\HW1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HW1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW1.dir/build: bin/HW1.exe

.PHONY : CMakeFiles/HW1.dir/build

CMakeFiles/HW1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HW1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HW1.dir/clean

CMakeFiles/HW1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Codefield\DS\HW1 D:\Codefield\DS\HW1 D:\Codefield\DS\HW1\build D:\Codefield\DS\HW1\build D:\Codefield\DS\HW1\build\CMakeFiles\HW1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW1.dir/depend

