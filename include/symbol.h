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

#ifndef HUFFMANCODING_SYMBOL_H
#define HUFFMANCODING_SYMBOL_H

#include <stdint.h>

typedef struct {
    char character;
    int frequency;
    int encoding[10];
    int encodingLength;
}symbol;

void getSymbols(const char *string, symbol *output);
void getSymbolsFrequency(const char *string, symbol *symbols, symbol *output);
uint32_t getSymbolsLen(const symbol *symbols);
void swapSymbols(symbol *operand1, symbol *operand2);
// This sorts in ascending frequency order following a selection sort approach
void sortSymbolArray(symbol *array, uint32_t arrayLength);

#endif //HUFFMANCODING_SYMBOL_H
