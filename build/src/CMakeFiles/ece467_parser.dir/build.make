# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /n/share/copy/ece467/bin/cmake

# The command to remove a file.
RM = /n/share/copy/ece467/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /u/d/rotbauer/ece467-1003963124

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /u/d/rotbauer/ece467-1003963124/build

# Include any dependencies generated for this target.
include src/CMakeFiles/ece467_parser.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ece467_parser.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ece467_parser.dir/flags.make

src/parser.cpp: ../src/parser.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/u/d/rotbauer/ece467-1003963124/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][ECE467Parser] Building parser with bison 3.7.2"
	cd /u/d/rotbauer/ece467-1003963124/build/src && /n/share/copy/ece467/bin/bison --defines=/u/d/rotbauer/ece467-1003963124/build/src/parser.hpp -o parser.cpp /u/d/rotbauer/ece467-1003963124/src/parser.y

src/parser.hpp: src/parser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate src/parser.hpp

src/CMakeFiles/ece467_parser.dir/parser.cpp.o: src/CMakeFiles/ece467_parser.dir/flags.make
src/CMakeFiles/ece467_parser.dir/parser.cpp.o: src/parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/u/d/rotbauer/ece467-1003963124/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/ece467_parser.dir/parser.cpp.o"
	cd /u/d/rotbauer/ece467-1003963124/build/src && /opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ece467_parser.dir/parser.cpp.o -c /u/d/rotbauer/ece467-1003963124/build/src/parser.cpp

src/CMakeFiles/ece467_parser.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ece467_parser.dir/parser.cpp.i"
	cd /u/d/rotbauer/ece467-1003963124/build/src && /opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/d/rotbauer/ece467-1003963124/build/src/parser.cpp > CMakeFiles/ece467_parser.dir/parser.cpp.i

src/CMakeFiles/ece467_parser.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ece467_parser.dir/parser.cpp.s"
	cd /u/d/rotbauer/ece467-1003963124/build/src && /opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/d/rotbauer/ece467-1003963124/build/src/parser.cpp -o CMakeFiles/ece467_parser.dir/parser.cpp.s

ece467_parser: src/CMakeFiles/ece467_parser.dir/parser.cpp.o
ece467_parser: src/CMakeFiles/ece467_parser.dir/build.make

.PHONY : ece467_parser

# Rule to build all files generated by this target.
src/CMakeFiles/ece467_parser.dir/build: ece467_parser

.PHONY : src/CMakeFiles/ece467_parser.dir/build

src/CMakeFiles/ece467_parser.dir/clean:
	cd /u/d/rotbauer/ece467-1003963124/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ece467_parser.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ece467_parser.dir/clean

src/CMakeFiles/ece467_parser.dir/depend: src/parser.cpp
src/CMakeFiles/ece467_parser.dir/depend: src/parser.hpp
	cd /u/d/rotbauer/ece467-1003963124/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/d/rotbauer/ece467-1003963124 /u/d/rotbauer/ece467-1003963124/src /u/d/rotbauer/ece467-1003963124/build /u/d/rotbauer/ece467-1003963124/build/src /u/d/rotbauer/ece467-1003963124/build/src/CMakeFiles/ece467_parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ece467_parser.dir/depend

