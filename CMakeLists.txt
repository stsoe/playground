cmake_minimum_required(VERSION 3.16)

project(playground)

# Enable testing for this directory and below.  This command should be
# in the source directory root because ctest expects to find a test
# file in the build directory root.
enable_testing()

#if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#  set(CMAKE_INSTALL_PREFIX "/opt/xilinx" CACHE PATH "..." FORCE)
#  message("-- Install prefix is default initialized to ${CMAKE_INSTALL_PREFIX}")
#endif()

message("-- Install prefix is set to ${CMAKE_INSTALL_PREFIX}")

add_subdirectory(src)
#add_subdirectory(glfw)
#add_subdirectory(xrt)

#message("--cii=${CMAKE_INSTALL_INCLUDEDIR}")
#message("--gdb=${GLFW_BINARY_DIR}")
#message("--gcp=${GLFW_CONFIG_PATH}")

message("--------CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}")
