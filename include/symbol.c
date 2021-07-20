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

#include <string.h>
#include <stdlib.h>
#include "symbol.h"

void getSymbols(const char *string, symbol *output) {
    char curSymbol = '\0';
    uint32_t numFoundSymbols = 0;
    uint32_t numIterations = strlen(string);
    for (uint32_t i = 0; i < numIterations; ++i) {
        curSymbol = string[i];
        for (uint32_t j = 0; j < numIterations; ++j) {
            if(curSymbol == output[j].character) {
                break;
            }
            else if (curSymbol != output[j].character && j == numIterations - 1) {
                output[numFoundSymbols++].character = curSymbol;
            }
        }
    }
}

void getSymbolsFrequency(const char *string, symbol *symbols, symbol *output) {
    uint32_t symbolslen = getSymbolsLen(symbols);

    for (uint32_t i = 0; i < symbolslen; ++i) {
        for (uint32_t j = 0; j < strlen(string); ++j) {
            if (symbols[i].character == string[j]) {
                ++output[i].frequency;
            }
        }
    }
}

uint32_t getSymbolsLen(const symbol *symbols) {
    uint32_t symbolslen = 0;

    while (symbols[symbolslen].character) {
        ++symbolslen;
    };
    return symbolslen;
}

void swapSymbols(symbol *operand1, symbol *operand2) {
    symbol temp = *operand1;
    *operand1 = *operand2;
    *operand2 = temp;
}

void sortSymbolArray(symbol *array, uint32_t arrayLength) {
    uint32_t minimumFrequencyIndex;

    for (uint32_t i = 0; i < arrayLength - 1; i++) {
        // Find symbol with minimum frequency
        minimumFrequencyIndex = i;
        for (uint32_t j = i + 1; j < arrayLength; j++) {
            if (array[j].frequency < array[minimumFrequencyIndex].frequency) {
                minimumFrequencyIndex = j;
            }
        }

        swapSymbols(&array[minimumFrequencyIndex], &array[i]);
    }
}
