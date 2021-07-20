cmake_minimum_required(VERSION 3.16)
project(HuffmanCodingDecompress C)

set(CMAKE_C_STANDARD 11)

add_executable(HuffmanCodingDecompress main.c ../include/node.c ../include/symbol.c ../include/encoding.c ../include/utility.c)