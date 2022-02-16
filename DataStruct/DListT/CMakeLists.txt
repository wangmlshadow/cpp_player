cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
#SET(CMAKE_CXX_STANDARD 11)
#SET(CMAKE_C_COMPILER /usr/bin/gcc)
#SET(CMAKE_CXX_COMPILER /usr/bin/gcc)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

project(Demo)

aux_source_directory(. DIR_SRCS)

add_executable(Demo ${DIR_SRCS})
