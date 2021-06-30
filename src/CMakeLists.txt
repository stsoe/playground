cmake_minimum_required(VERSION 3.16)

project(main)

add_custom_command(
  OUTPUT gc.txt
  COMMAND touch gc.txt
)
add_custom_target(pcie_emulation_generated_code DEPENDS gc.txt)
add_custom_target(edge_emulation_generated_code DEPENDS gc.txt)

add_executable(main hello.cpp)

install(TARGETS main)

enable_testing()
add_test(NAME main COMMAND main)
