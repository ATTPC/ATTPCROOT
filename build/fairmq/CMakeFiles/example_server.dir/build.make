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
CMAKE_COMMAND = "/Applications/CMake 2.8-10.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-10.app/Contents/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-10.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build

# Include any dependencies generated for this target.
include fairmq/CMakeFiles/example_server.dir/depend.make

# Include the progress variables for this target.
include fairmq/CMakeFiles/example_server.dir/progress.make

# Include the compile flags for this target's objects.
include fairmq/CMakeFiles/example_server.dir/flags.make

fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o: fairmq/CMakeFiles/example_server.dir/flags.make
fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o: ../fairmq/examples/req-rep/runExampleServer.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o"
	cd /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/fairmq && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o -c /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/examples/req-rep/runExampleServer.cxx

fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.i"
	cd /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/fairmq && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/examples/req-rep/runExampleServer.cxx > CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.i

fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.s"
	cd /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/fairmq && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq/examples/req-rep/runExampleServer.cxx -o CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.s

fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o.requires:
.PHONY : fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o.requires

fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o.provides: fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o.requires
	$(MAKE) -f fairmq/CMakeFiles/example_server.dir/build.make fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o.provides.build
.PHONY : fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o.provides

fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o.provides.build: fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o

# Object files for target example_server
example_server_OBJECTS = \
"CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o"

# External object files for target example_server
example_server_EXTERNAL_OBJECTS =

bin/example_server: fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o
bin/example_server: fairmq/CMakeFiles/example_server.dir/build.make
bin/example_server: lib/libFairMQ.0.0.0.so
bin/example_server: /Users/yassidayyad/fair_install/FairSoftInst/lib64/libzmq.so
bin/example_server: fairmq/CMakeFiles/example_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/example_server"
	cd /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/fairmq && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
fairmq/CMakeFiles/example_server.dir/build: bin/example_server
.PHONY : fairmq/CMakeFiles/example_server.dir/build

fairmq/CMakeFiles/example_server.dir/requires: fairmq/CMakeFiles/example_server.dir/examples/req-rep/runExampleServer.cxx.o.requires
.PHONY : fairmq/CMakeFiles/example_server.dir/requires

fairmq/CMakeFiles/example_server.dir/clean:
	cd /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/fairmq && $(CMAKE_COMMAND) -P CMakeFiles/example_server.dir/cmake_clean.cmake
.PHONY : fairmq/CMakeFiles/example_server.dir/clean

fairmq/CMakeFiles/example_server.dir/depend:
	cd /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/fairmq /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/fairmq /Users/yassidayyad/fair_install/ATTPCROOT_Mar_dev/build/fairmq/CMakeFiles/example_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : fairmq/CMakeFiles/example_server.dir/depend

