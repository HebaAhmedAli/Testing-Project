# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2017.1.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.1.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Testing-Project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Testing-Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Testing-Project.dir/flags.make

CMakeFiles/Testing-Project.dir/main.cpp.o: CMakeFiles/Testing-Project.dir/flags.make
CMakeFiles/Testing-Project.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Testing-Project.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Testing-Project.dir/main.cpp.o -c /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/main.cpp

CMakeFiles/Testing-Project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Testing-Project.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/main.cpp > CMakeFiles/Testing-Project.dir/main.cpp.i

CMakeFiles/Testing-Project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Testing-Project.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/main.cpp -o CMakeFiles/Testing-Project.dir/main.cpp.s

CMakeFiles/Testing-Project.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Testing-Project.dir/main.cpp.o.requires

CMakeFiles/Testing-Project.dir/main.cpp.o.provides: CMakeFiles/Testing-Project.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Testing-Project.dir/build.make CMakeFiles/Testing-Project.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Testing-Project.dir/main.cpp.o.provides

CMakeFiles/Testing-Project.dir/main.cpp.o.provides.build: CMakeFiles/Testing-Project.dir/main.cpp.o


CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o: CMakeFiles/Testing-Project.dir/flags.make
CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o: ../tests/gtest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o -c /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/tests/gtest.cpp

CMakeFiles/Testing-Project.dir/tests/gtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Testing-Project.dir/tests/gtest.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/tests/gtest.cpp > CMakeFiles/Testing-Project.dir/tests/gtest.cpp.i

CMakeFiles/Testing-Project.dir/tests/gtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Testing-Project.dir/tests/gtest.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/tests/gtest.cpp -o CMakeFiles/Testing-Project.dir/tests/gtest.cpp.s

CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o.requires:

.PHONY : CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o.requires

CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o.provides: CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o.requires
	$(MAKE) -f CMakeFiles/Testing-Project.dir/build.make CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o.provides.build
.PHONY : CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o.provides

CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o.provides.build: CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o


CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o: CMakeFiles/Testing-Project.dir/flags.make
CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o: ../tests/gtest_fixture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o -c /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/tests/gtest_fixture.cpp

CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/tests/gtest_fixture.cpp > CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.i

CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/tests/gtest_fixture.cpp -o CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.s

CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o.requires:

.PHONY : CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o.requires

CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o.provides: CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o.requires
	$(MAKE) -f CMakeFiles/Testing-Project.dir/build.make CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o.provides.build
.PHONY : CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o.provides

CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o.provides.build: CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o


# Object files for target Testing-Project
Testing__Project_OBJECTS = \
"CMakeFiles/Testing-Project.dir/main.cpp.o" \
"CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o" \
"CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o"

# External object files for target Testing-Project
Testing__Project_EXTERNAL_OBJECTS =

Testing-Project: CMakeFiles/Testing-Project.dir/main.cpp.o
Testing-Project: CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o
Testing-Project: CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o
Testing-Project: CMakeFiles/Testing-Project.dir/build.make
Testing-Project: lib/libgtestd.a
Testing-Project: lib/libgtest_maind.a
Testing-Project: lib/libgtestd.a
Testing-Project: CMakeFiles/Testing-Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Testing-Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Testing-Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Testing-Project.dir/build: Testing-Project

.PHONY : CMakeFiles/Testing-Project.dir/build

CMakeFiles/Testing-Project.dir/requires: CMakeFiles/Testing-Project.dir/main.cpp.o.requires
CMakeFiles/Testing-Project.dir/requires: CMakeFiles/Testing-Project.dir/tests/gtest.cpp.o.requires
CMakeFiles/Testing-Project.dir/requires: CMakeFiles/Testing-Project.dir/tests/gtest_fixture.cpp.o.requires

.PHONY : CMakeFiles/Testing-Project.dir/requires

CMakeFiles/Testing-Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Testing-Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Testing-Project.dir/clean

CMakeFiles/Testing-Project.dir/depend:
	cd /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/CMakeFiles/Testing-Project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Testing-Project.dir/depend

