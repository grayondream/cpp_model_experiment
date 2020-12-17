cmake_minimum_required(VERSION 3.5)

#set(CMAKE_CXX_COMPILER /usr/bin/clang++)
project(main)

include_directories(include)
include_directories(test)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(src SRC_DIR)
aux_source_directory(test TEST_DIR)


add_executable(main  ${SRC_DIR} ${TEST_DIR})