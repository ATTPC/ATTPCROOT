# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daq/fair_install_2015/ATTPCROOT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daq/fair_install_2015/ATTPCROOT/build

# Utility rule file for libPassive.rootmap.

# Include the progress variables for this target.
include passive/CMakeFiles/libPassive.rootmap.dir/progress.make

passive/CMakeFiles/libPassive.rootmap: lib/libPassive.rootmap

lib/libPassive.rootmap: ../passive/PassiveLinkDef.h
lib/libPassive.rootmap: ../passive/PassiveLinkDef.h
lib/libPassive.rootmap: /usr/local/fairsoft/fairsoft_jul14p3-install/bin/rlibmap
	$(CMAKE_COMMAND) -E cmake_progress_report /home/daq/fair_install_2015/ATTPCROOT/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../lib/libPassive.rootmap"
	cd /home/daq/fair_install_2015/ATTPCROOT/build/passive && /usr/local/fairsoft/fairsoft_jul14p3-install/bin/rlibmap -o /home/daq/fair_install_2015/ATTPCROOT/build/lib/libPassive.rootmap -l Passive -d libBase.so libGeoBase.so libParBase.so libGeom.so libCint.so libCore.so -c PassiveLinkDef.h /home/daq/fair_install_2015/ATTPCROOT/passive/PassiveLinkDef.h

libPassive.rootmap: passive/CMakeFiles/libPassive.rootmap
libPassive.rootmap: lib/libPassive.rootmap
libPassive.rootmap: passive/CMakeFiles/libPassive.rootmap.dir/build.make
.PHONY : libPassive.rootmap

# Rule to build all files generated by this target.
passive/CMakeFiles/libPassive.rootmap.dir/build: libPassive.rootmap
.PHONY : passive/CMakeFiles/libPassive.rootmap.dir/build

passive/CMakeFiles/libPassive.rootmap.dir/clean:
	cd /home/daq/fair_install_2015/ATTPCROOT/build/passive && $(CMAKE_COMMAND) -P CMakeFiles/libPassive.rootmap.dir/cmake_clean.cmake
.PHONY : passive/CMakeFiles/libPassive.rootmap.dir/clean

passive/CMakeFiles/libPassive.rootmap.dir/depend:
	cd /home/daq/fair_install_2015/ATTPCROOT/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daq/fair_install_2015/ATTPCROOT /home/daq/fair_install_2015/ATTPCROOT/passive /home/daq/fair_install_2015/ATTPCROOT/build /home/daq/fair_install_2015/ATTPCROOT/build/passive /home/daq/fair_install_2015/ATTPCROOT/build/passive/CMakeFiles/libPassive.rootmap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : passive/CMakeFiles/libPassive.rootmap.dir/depend

