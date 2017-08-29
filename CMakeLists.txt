cmake_minimum_required(VERSION 3.8)
project(gbemu)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cpu.cpp cpu.h opcodes.cpp cbopcodes.cpp opcodeHelper.cpp)
add_executable(gbemu ${SOURCE_FILES} cpu.cpp opcodes.cpp cbopcodes.cpp)