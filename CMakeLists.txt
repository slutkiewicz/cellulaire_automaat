cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project (cellulaire_automaat CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${cellulaire_automaat_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/thirdparty)
include_directories("${PROJECT_SOURCE_DIR}/src")

file(GLOB_RECURSE cellulaire_automaat_SOURCES "src/*.cpp")
file(GLOB_RECURSE thirdparty_SOURCES "thirdparty/*.cpp")

add_executable(cellulaire_automaat ${cellulaire_automaat_SOURCES} ${thirdparty_SOURCES})
target_link_libraries(cellulaire_automaat ${SDL2_LIBRARIES})

add_custom_command(TARGET cellulaire_automaat PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:cellulaire_automaat>/data)
