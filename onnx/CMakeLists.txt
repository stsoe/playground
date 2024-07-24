cmake_minimum_required(VERSION 3.23)
project(G2O LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

# pdb
add_compile_options(/Zc:__cplusplus /Zi)
add_link_options(/DEBUG)

cmake_policy(SET CMP0144 NEW)
set(PROTOBUF_ROOT c:/Users/msft/tools)
find_package(Protobuf REQUIRED)

add_library(graph2onnx STATIC
  graph2onnx.cpp
  onnx.proto3.pb.cc
)

set_source_files_properties(onnx.proto3.pb.cc PROPERTIES COMPILE_FLAGS /wd4267)

target_include_directories(graph2onnx
  PRIVATE
  ${Protobuf_INCLUDE_DIRS}
)

target_link_libraries(graph2onnx
  PUBLIC
  ${Protobuf_LIBRARIES}
)

add_executable(host main.cpp)
target_link_libraries(host PRIVATE graph2onnx)

  
