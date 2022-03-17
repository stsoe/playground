cmake_minimum_required(VERSION 3.16)

project(playground)

add_subdirectory(src)
add_subdirectory(glfw)
#add_subdirectory(xrt)

#message("--cii=${CMAKE_INSTALL_INCLUDEDIR}")
#message("--gdb=${GLFW_BINARY_DIR}")
#message("--gcp=${GLFW_CONFIG_PATH}")

install(TARGETS main)
