# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/crivac/robocomp/components/roboticaCC/apriltagsMASTER

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crivac/robocomp/components/roboticaCC/apriltagsMASTER

# Utility rule file for AprilTagsComp_automoc.

# Include the progress variables for this target.
include src/CMakeFiles/AprilTagsComp_automoc.dir/progress.make

src/CMakeFiles/AprilTagsComp_automoc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/crivac/robocomp/components/roboticaCC/apriltagsMASTER/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic moc for target AprilTagsComp"
	cd /home/crivac/robocomp/components/roboticaCC/apriltagsMASTER/src && /usr/bin/cmake -E cmake_autogen /home/crivac/robocomp/components/roboticaCC/apriltagsMASTER/src/CMakeFiles/AprilTagsComp_automoc.dir/ ""

AprilTagsComp_automoc: src/CMakeFiles/AprilTagsComp_automoc
AprilTagsComp_automoc: src/CMakeFiles/AprilTagsComp_automoc.dir/build.make

.PHONY : AprilTagsComp_automoc

# Rule to build all files generated by this target.
src/CMakeFiles/AprilTagsComp_automoc.dir/build: AprilTagsComp_automoc

.PHONY : src/CMakeFiles/AprilTagsComp_automoc.dir/build

src/CMakeFiles/AprilTagsComp_automoc.dir/clean:
	cd /home/crivac/robocomp/components/roboticaCC/apriltagsMASTER/src && $(CMAKE_COMMAND) -P CMakeFiles/AprilTagsComp_automoc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/AprilTagsComp_automoc.dir/clean

src/CMakeFiles/AprilTagsComp_automoc.dir/depend:
	cd /home/crivac/robocomp/components/roboticaCC/apriltagsMASTER && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crivac/robocomp/components/roboticaCC/apriltagsMASTER /home/crivac/robocomp/components/roboticaCC/apriltagsMASTER/src /home/crivac/robocomp/components/roboticaCC/apriltagsMASTER /home/crivac/robocomp/components/roboticaCC/apriltagsMASTER/src /home/crivac/robocomp/components/roboticaCC/apriltagsMASTER/src/CMakeFiles/AprilTagsComp_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/AprilTagsComp_automoc.dir/depend

