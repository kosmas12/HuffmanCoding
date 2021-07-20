/*
    This file is part of HuffmanCoding - A C implementation of the Huffman coding algorithm
    Copyright (C) 2021 Kosmas Raptis

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef HUFFMANCODING_UTILITY_H
#define HUFFMANCODING_UTILITY_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"

void writeDictionaryToFile(const symbol dictionary[], FILE *file);
void writeEncodedStringToFile(const int encodedString[], FILE *file, int length);
void setBit(unsigned char *value, uint8_t bitToSet, int set);
symbol *getDictionaryFromFile(FILE *file);

#endif //HUFFMANCODING_UTILITY_H
