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
include CMakeFiles/changyongPaixu.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/changyongPaixu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/changyongPaixu.dir/flags.make

CMakeFiles/changyongPaixu.dir/changyongPaixu.cpp.obj: CMakeFiles/changyongPaixu.dir/flags.make
CMakeFiles/changyongPaixu.dir/changyongPaixu.cpp.obj: ../changyongPaixu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\c++stl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/changyongPaixu.dir/changyongPaixu.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\changyongPaixu.dir\changyongPaixu.cpp.obj -c D:\c++stl\changyongPaixu.cpp

CMakeFiles/changyongPaixu.dir/changyongPaixu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/changyongPaixu.dir/changyongPaixu.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\c++stl\changyongPaixu.cpp > CMakeFiles\changyongPaixu.dir\changyongPaixu.cpp.i

CMakeFiles/changyongPaixu.dir/changyongPaixu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/changyongPaixu.dir/changyongPaixu.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\c++stl\changyongPaixu.cpp -o CMakeFiles\changyongPaixu.dir\changyongPaixu.cpp.s

# Object files for target changyongPaixu
changyongPaixu_OBJECTS = \
"CMakeFiles/changyongPaixu.dir/changyongPaixu.cpp.obj"

# External object files for target changyongPaixu
changyongPaixu_EXTERNAL_OBJECTS =

changyongPaixu.exe: CMakeFiles/changyongPaixu.dir/changyongPaixu.cpp.obj
changyongPaixu.exe: CMakeFiles/changyongPaixu.dir/build.make
changyongPaixu.exe: CMakeFiles/changyongPaixu.dir/linklibs.rsp
changyongPaixu.exe: CMakeFiles/changyongPaixu.dir/objects1.rsp
changyongPaixu.exe: CMakeFiles/changyongPaixu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\c++stl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable changyongPaixu.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\changyongPaixu.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/changyongPaixu.dir/build: changyongPaixu.exe

.PHONY : CMakeFiles/changyongPaixu.dir/build

CMakeFiles/changyongPaixu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\changyongPaixu.dir\cmake_clean.cmake
.PHONY : CMakeFiles/changyongPaixu.dir/clean

CMakeFiles/changyongPaixu.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\c++stl D:\c++stl D:\c++stl\cmake-build-debug D:\c++stl\cmake-build-debug D:\c++stl\cmake-build-debug\CMakeFiles\changyongPaixu.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/changyongPaixu.dir/depend

