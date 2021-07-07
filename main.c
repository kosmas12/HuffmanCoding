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

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>
#include "include/node.h"
#include "include/symbol.h"

int main() {
    //struct node *testNode = newNode(0);

    const char *string = "Hello World!";
    // Allocate enough memory for worst case scenario: Every character is unique
    symbol *symbols = (symbol *) calloc(sizeof(symbol), strlen(string));
    getSymbols(string, symbols);

    printf("String \"%s\" with each character appearing once is \"", string);
    for (unsigned long i = 0; i < strlen(string); ++i) {
        printf("%c", symbols[i].character);
    }
    printf("\"\n");

    getSymbolsFrequency(string, symbols, symbols);

    unsigned long symbolsArrayLength = getSymbolsLen(symbols);

    printf("String \"%s\" has these symbols:\n", string);

    for (unsigned long i = 0; i < symbolsArrayLength; ++i) {
        printf("%c appearing %d times\n", symbols[i].character, symbols[i].frequency);
    }

    sortSymbolArray(symbols, symbolsArrayLength);

    free(symbols);
    return 0;
}
