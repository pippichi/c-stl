# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "D:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\c++stl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\c++stl\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dequeDafenAnli.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dequeDafenAnli.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dequeDafenAnli.dir/flags.make

CMakeFiles/dequeDafenAnli.dir/dequeDafenAnli.cpp.obj: CMakeFiles/dequeDafenAnli.dir/flags.make
CMakeFiles/dequeDafenAnli.dir/dequeDafenAnli.cpp.obj: ../dequeDafenAnli.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\c++stl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dequeDafenAnli.dir/dequeDafenAnli.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\dequeDafenAnli.dir\dequeDafenAnli.cpp.obj -c D:\c++stl\dequeDafenAnli.cpp

CMakeFiles/dequeDafenAnli.dir/dequeDafenAnli.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dequeDafenAnli.dir/dequeDafenAnli.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\c++stl\dequeDafenAnli.cpp > CMakeFiles\dequeDafenAnli.dir\dequeDafenAnli.cpp.i

CMakeFiles/dequeDafenAnli.dir/dequeDafenAnli.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dequeDafenAnli.dir/dequeDafenAnli.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\c++stl\dequeDafenAnli.cpp -o CMakeFiles\dequeDafenAnli.dir\dequeDafenAnli.cpp.s

# Object files for target dequeDafenAnli
dequeDafenAnli_OBJECTS = \
"CMakeFiles/dequeDafenAnli.dir/dequeDafenAnli.cpp.obj"

# External object files for target dequeDafenAnli
dequeDafenAnli_EXTERNAL_OBJECTS =

dequeDafenAnli.exe: CMakeFiles/dequeDafenAnli.dir/dequeDafenAnli.cpp.obj
dequeDafenAnli.exe: CMakeFiles/dequeDafenAnli.dir/build.make
dequeDafenAnli.exe: CMakeFiles/dequeDafenAnli.dir/linklibs.rsp
dequeDafenAnli.exe: CMakeFiles/dequeDafenAnli.dir/objects1.rsp
dequeDafenAnli.exe: CMakeFiles/dequeDafenAnli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\c++stl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dequeDafenAnli.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\dequeDafenAnli.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dequeDafenAnli.dir/build: dequeDafenAnli.exe

.PHONY : CMakeFiles/dequeDafenAnli.dir/build

CMakeFiles/dequeDafenAnli.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\dequeDafenAnli.dir\cmake_clean.cmake
.PHONY : CMakeFiles/dequeDafenAnli.dir/clean

CMakeFiles/dequeDafenAnli.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\c++stl D:\c++stl D:\c++stl\cmake-build-debug D:\c++stl\cmake-build-debug D:\c++stl\cmake-build-debug\CMakeFiles\dequeDafenAnli.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dequeDafenAnli.dir/depend
