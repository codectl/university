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

# Include any dependencies generated for this target.
include addons/physfs/CMakeFiles/allegro_physfs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include addons/physfs/CMakeFiles/allegro_physfs.dir/compiler_depend.make

# Include the progress variables for this target.
include addons/physfs/CMakeFiles/allegro_physfs.dir/progress.make

# Include the compile flags for this target's objects.
include addons/physfs/CMakeFiles/allegro_physfs.dir/flags.make

addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs.c.o: addons/physfs/CMakeFiles/allegro_physfs.dir/flags.make
addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs.c.o: ../addons/physfs/a5_physfs.c
addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs.c.o: addons/physfs/CMakeFiles/allegro_physfs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/physfs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs.c.o -MF CMakeFiles/allegro_physfs.dir/a5_physfs.c.o.d -o CMakeFiles/allegro_physfs.dir/a5_physfs.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/physfs/a5_physfs.c

addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_physfs.dir/a5_physfs.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/physfs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/physfs/a5_physfs.c > CMakeFiles/allegro_physfs.dir/a5_physfs.c.i

addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_physfs.dir/a5_physfs.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/physfs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/physfs/a5_physfs.c -o CMakeFiles/allegro_physfs.dir/a5_physfs.c.s

addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.o: addons/physfs/CMakeFiles/allegro_physfs.dir/flags.make
addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.o: ../addons/physfs/a5_physfs_dir.c
addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.o: addons/physfs/CMakeFiles/allegro_physfs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/physfs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.o -MF CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.o.d -o CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/physfs/a5_physfs_dir.c

addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/physfs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/physfs/a5_physfs_dir.c > CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.i

addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/physfs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/physfs/a5_physfs_dir.c -o CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.s

# Object files for target allegro_physfs
allegro_physfs_OBJECTS = \
"CMakeFiles/allegro_physfs.dir/a5_physfs.c.o" \
"CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.o"

# External object files for target allegro_physfs
allegro_physfs_EXTERNAL_OBJECTS =

lib/liballegro_physfs.5.2.7.dylib: addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs.c.o
lib/liballegro_physfs.5.2.7.dylib: addons/physfs/CMakeFiles/allegro_physfs.dir/a5_physfs_dir.c.o
lib/liballegro_physfs.5.2.7.dylib: addons/physfs/CMakeFiles/allegro_physfs.dir/build.make
lib/liballegro_physfs.5.2.7.dylib: lib/liballegro.5.2.7.dylib
lib/liballegro_physfs.5.2.7.dylib: /usr/local/lib/libphysfs.dylib
lib/liballegro_physfs.5.2.7.dylib: addons/physfs/CMakeFiles/allegro_physfs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library ../../lib/liballegro_physfs.dylib"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/physfs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allegro_physfs.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/physfs && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/liballegro_physfs.5.2.7.dylib ../../lib/liballegro_physfs.5.2.dylib ../../lib/liballegro_physfs.dylib

lib/liballegro_physfs.5.2.dylib: lib/liballegro_physfs.5.2.7.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/liballegro_physfs.5.2.dylib

lib/liballegro_physfs.dylib: lib/liballegro_physfs.5.2.7.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/liballegro_physfs.dylib

# Rule to build all files generated by this target.
addons/physfs/CMakeFiles/allegro_physfs.dir/build: lib/liballegro_physfs.dylib
.PHONY : addons/physfs/CMakeFiles/allegro_physfs.dir/build

addons/physfs/CMakeFiles/allegro_physfs.dir/clean:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/physfs && $(CMAKE_COMMAND) -P CMakeFiles/allegro_physfs.dir/cmake_clean.cmake
.PHONY : addons/physfs/CMakeFiles/allegro_physfs.dir/clean

addons/physfs/CMakeFiles/allegro_physfs.dir/depend:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0 /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/physfs /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/physfs /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/physfs/CMakeFiles/allegro_physfs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : addons/physfs/CMakeFiles/allegro_physfs.dir/depend
