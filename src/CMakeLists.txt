if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

add_executable(main hello.cpp)
install(TARGETS main)
