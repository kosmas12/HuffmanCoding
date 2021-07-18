cmake_minimum_required(VERSION 3.19)
project(HuffmanCoding C)

set(CMAKE_C_STANDARD 11)

add_executable(HuffmanCoding main.c include/node.c include/symbol.c include/encoding.c)