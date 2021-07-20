cmake_minimum_required(VERSION 3.16)
project(HuffmanCoding C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/compress)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/decompress)
