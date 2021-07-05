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

void getSymbols(const char *string, char *output) {
    char curSymbol = '\0';
    uint16_t numFoundSymbols = 0;
    uint16_t numIterations = strlen(string);
    for (uint16_t i = 0; i < numIterations; ++i) {
        curSymbol = string[i];
        for (uint16_t j = 0; j < numIterations; ++j) {
            if(curSymbol == output[j]) {
                break;
            }
            else if (curSymbol != output[j] && j == numIterations - 1) {
                output[numFoundSymbols++] = curSymbol;
            }
        }
    }
}

int main() {
    //struct node *testNode = newNode(0);

    const char *string = "Hello World!";
    char *symbols = (char *) calloc(1, strlen(string));
    getSymbols(string, symbols);

    printf("%s\n", symbols);

    free(symbols);

    return 0;
}
