# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Programming\Structures\C++Structures\stack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Programming\Structures\C++Structures\stack\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stack.dir/flags.make

CMakeFiles/stack.dir/main.cpp.obj: CMakeFiles/stack.dir/flags.make
CMakeFiles/stack.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Programming\Structures\C++Structures\stack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stack.dir/main.cpp.obj"
	E:\mingw-w64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\stack.dir\main.cpp.obj -c E:\Programming\Structures\C++Structures\stack\main.cpp

CMakeFiles/stack.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stack.dir/main.cpp.i"
	E:\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Programming\Structures\C++Structures\stack\main.cpp > CMakeFiles\stack.dir\main.cpp.i

CMakeFiles/stack.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stack.dir/main.cpp.s"
	E:\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Programming\Structures\C++Structures\stack\main.cpp -o CMakeFiles\stack.dir\main.cpp.s

CMakeFiles/stack.dir/stack_linked.cpp.obj: CMakeFiles/stack.dir/flags.make
CMakeFiles/stack.dir/stack_linked.cpp.obj: ../stack_linked.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Programming\Structures\C++Structures\stack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/stack.dir/stack_linked.cpp.obj"
	E:\mingw-w64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\stack.dir\stack_linked.cpp.obj -c E:\Programming\Structures\C++Structures\stack\stack_linked.cpp

CMakeFiles/stack.dir/stack_linked.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stack.dir/stack_linked.cpp.i"
	E:\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Programming\Structures\C++Structures\stack\stack_linked.cpp > CMakeFiles\stack.dir\stack_linked.cpp.i

CMakeFiles/stack.dir/stack_linked.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stack.dir/stack_linked.cpp.s"
	E:\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Programming\Structures\C++Structures\stack\stack_linked.cpp -o CMakeFiles\stack.dir\stack_linked.cpp.s

# Object files for target stack
stack_OBJECTS = \
"CMakeFiles/stack.dir/main.cpp.obj" \
"CMakeFiles/stack.dir/stack_linked.cpp.obj"

# External object files for target stack
stack_EXTERNAL_OBJECTS =

stack.exe: CMakeFiles/stack.dir/main.cpp.obj
stack.exe: CMakeFiles/stack.dir/stack_linked.cpp.obj
stack.exe: CMakeFiles/stack.dir/build.make
stack.exe: CMakeFiles/stack.dir/linklibs.rsp
stack.exe: CMakeFiles/stack.dir/objects1.rsp
stack.exe: CMakeFiles/stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Programming\Structures\C++Structures\stack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable stack.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\stack.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stack.dir/build: stack.exe

.PHONY : CMakeFiles/stack.dir/build

CMakeFiles/stack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\stack.dir\cmake_clean.cmake
.PHONY : CMakeFiles/stack.dir/clean

CMakeFiles/stack.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Programming\Structures\C++Structures\stack E:\Programming\Structures\C++Structures\stack E:\Programming\Structures\C++Structures\stack\cmake-build-debug E:\Programming\Structures\C++Structures\stack\cmake-build-debug E:\Programming\Structures\C++Structures\stack\cmake-build-debug\CMakeFiles\stack.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stack.dir/depend

