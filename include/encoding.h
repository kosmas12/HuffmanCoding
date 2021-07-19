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

#ifndef HUFFMANCODING_ENCODING_H
#define HUFFMANCODING_ENCODING_H

#include "node.h"

void printEncoding(int *encoding, int encodingLength);
void generateAndPrintEncoding(struct node *root, symbol symbols[], int encoding[], int start);
int *generateEncodedString(const char *string, const symbol symbols[]);

#endif //HUFFMANCODING_ENCODING_H
