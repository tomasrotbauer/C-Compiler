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

# Utility rule file for intrinsics_gen.

# Include the progress variables for this target.
include src/CMakeFiles/intrinsics_gen.dir/progress.make

intrinsics_gen: src/CMakeFiles/intrinsics_gen.dir/build.make

.PHONY : intrinsics_gen

# Rule to build all files generated by this target.
src/CMakeFiles/intrinsics_gen.dir/build: intrinsics_gen

.PHONY : src/CMakeFiles/intrinsics_gen.dir/build

src/CMakeFiles/intrinsics_gen.dir/clean:
	cd /u/d/rotbauer/ece467-1003963124/build/src && $(CMAKE_COMMAND) -P CMakeFiles/intrinsics_gen.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/intrinsics_gen.dir/clean

src/CMakeFiles/intrinsics_gen.dir/depend:
	cd /u/d/rotbauer/ece467-1003963124/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/d/rotbauer/ece467-1003963124 /u/d/rotbauer/ece467-1003963124/src /u/d/rotbauer/ece467-1003963124/build /u/d/rotbauer/ece467-1003963124/build/src /u/d/rotbauer/ece467-1003963124/build/src/CMakeFiles/intrinsics_gen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/intrinsics_gen.dir/depend
