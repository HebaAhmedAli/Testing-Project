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
include tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../tests/lib/googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/tests/lib/googletest/googlemock/gtest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/tests/lib/googletest/googletest/src/gtest-all.cc

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/tests/lib/googletest/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/tests/lib/googletest/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/tests/lib/googletest/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/tests/lib/googletest/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires:

.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
	$(MAKE) -f tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/build.make tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build
.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtestd.a: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtestd.a: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/build.make
lib/libgtestd.a: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../../lib/libgtestd.a"
	cd /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/tests/lib/googletest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/tests/lib/googletest/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/build: lib/libgtestd.a

.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/build

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/requires: tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/requires

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/tests/lib/googletest/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/clean

tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	cd /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/tests/lib/googletest/googletest /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/tests/lib/googletest/googlemock/gtest /home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/cmake-build-debug/tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/lib/googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend

