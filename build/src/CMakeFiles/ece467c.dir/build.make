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
include src/CMakeFiles/ece467c.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ece467c.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ece467c.dir/flags.make

src/CMakeFiles/ece467c.dir/main.cpp.o: src/CMakeFiles/ece467c.dir/flags.make
src/CMakeFiles/ece467c.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/u/d/rotbauer/ece467-1003963124/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ece467c.dir/main.cpp.o"
	cd /u/d/rotbauer/ece467-1003963124/build/src && /opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ece467c.dir/main.cpp.o -c /u/d/rotbauer/ece467-1003963124/src/main.cpp

src/CMakeFiles/ece467c.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ece467c.dir/main.cpp.i"
	cd /u/d/rotbauer/ece467-1003963124/build/src && /opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /u/d/rotbauer/ece467-1003963124/src/main.cpp > CMakeFiles/ece467c.dir/main.cpp.i

src/CMakeFiles/ece467c.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ece467c.dir/main.cpp.s"
	cd /u/d/rotbauer/ece467-1003963124/build/src && /opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /u/d/rotbauer/ece467-1003963124/src/main.cpp -o CMakeFiles/ece467c.dir/main.cpp.s

# Object files for target ece467c
ece467c_OBJECTS = \
"CMakeFiles/ece467c.dir/main.cpp.o"

# External object files for target ece467c
ece467c_EXTERNAL_OBJECTS =

src/ece467c: src/CMakeFiles/ece467c.dir/main.cpp.o
src/ece467c: src/CMakeFiles/ece467c.dir/build.make
src/ece467c: src/libece467.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMInterpreter.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMOrcJIT.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMExecutionEngine.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMJITLink.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMOrcError.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMPasses.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMipo.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMInstrumentation.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMVectorize.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMIRReader.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMAsmParser.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMLinker.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMRuntimeDyld.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMX86CodeGen.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMAsmPrinter.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMDebugInfoDWARF.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMCFGuard.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMGlobalISel.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMSelectionDAG.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMCodeGen.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMBitWriter.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMScalarOpts.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMAggressiveInstCombine.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMInstCombine.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMTarget.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMTransformUtils.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMAnalysis.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMProfileData.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMX86AsmParser.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMX86Desc.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMObject.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMBitReader.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMCore.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMRemarks.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMBitstreamReader.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMMCParser.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMTextAPI.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMX86Disassembler.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMMCDisassembler.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMMC.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMBinaryFormat.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMDebugInfoCodeView.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMDebugInfoMSF.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMX86Info.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMX86Utils.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMSupport.a
src/ece467c: /n/share/copy/ece467/lib/libLLVMDemangle.a
src/ece467c: src/CMakeFiles/ece467c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/u/d/rotbauer/ece467-1003963124/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ece467c"
	cd /u/d/rotbauer/ece467-1003963124/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ece467c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ece467c.dir/build: src/ece467c

.PHONY : src/CMakeFiles/ece467c.dir/build

src/CMakeFiles/ece467c.dir/clean:
	cd /u/d/rotbauer/ece467-1003963124/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ece467c.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ece467c.dir/clean

src/CMakeFiles/ece467c.dir/depend:
	cd /u/d/rotbauer/ece467-1003963124/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/d/rotbauer/ece467-1003963124 /u/d/rotbauer/ece467-1003963124/src /u/d/rotbauer/ece467-1003963124/build /u/d/rotbauer/ece467-1003963124/build/src /u/d/rotbauer/ece467-1003963124/build/src/CMakeFiles/ece467c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ece467c.dir/depend

