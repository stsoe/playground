find_package(Boost REQUIRED)
message("-- Boost_INCLUDE_DIRS=${Boost_INCLUDE_DIRS}")

add_executable(main hello.cpp)
target_include_directories(main ${Boost_INCLUDE_DIRS})
install(TARGETS main)
