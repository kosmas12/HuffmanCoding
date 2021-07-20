cmake_minimum_required(VERSION 3.16)
project(HuffmanCodingCompress C)

set(CMAKE_C_STANDARD 11)

add_executable(HuffmanCodingCompress main.c ../include/node.c ../include/symbol.c ../include/encoding.c ../include/utility.c)