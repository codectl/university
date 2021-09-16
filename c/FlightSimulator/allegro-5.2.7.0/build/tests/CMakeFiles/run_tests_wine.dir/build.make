# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build

# Utility rule file for run_tests_wine.

# Include any custom commands dependencies for this target.
include tests/CMakeFiles/run_tests_wine.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/run_tests_wine.dir/progress.make

tests/CMakeFiles/run_tests_wine: tests/test_driver
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/tests && wine test_driver /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_bitmaps.ini /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_bitmaps2.ini /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_blend.ini /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_locking.ini /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_locking2.ini /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_backbuffer.ini /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_image.ini /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_fonts.ini /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_prim.ini /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_prim2.ini /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_convert.ini /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests/test_ciede2000.ini

run_tests_wine: tests/CMakeFiles/run_tests_wine
run_tests_wine: tests/CMakeFiles/run_tests_wine.dir/build.make
.PHONY : run_tests_wine

# Rule to build all files generated by this target.
tests/CMakeFiles/run_tests_wine.dir/build: run_tests_wine
.PHONY : tests/CMakeFiles/run_tests_wine.dir/build

tests/CMakeFiles/run_tests_wine.dir/clean:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/run_tests_wine.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/run_tests_wine.dir/clean

tests/CMakeFiles/run_tests_wine.dir/depend:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0 /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/tests /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/tests /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/tests/CMakeFiles/run_tests_wine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/run_tests_wine.dir/depend

