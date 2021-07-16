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
#include "include/node.h"
#include "include/symbol.h"

void removeElementsFromNodeArray(struct node **array, int numElements, unsigned long arrayLength) {
    int removedElements = 0;
    for (int i = 0; i < arrayLength; ++i) {
        if(array[i]->data.character != (char) 0 && removedElements < numElements) {
            for (int j = i; j < arrayLength - 1; ++j) {
                *array[j] = *array[j + 1];
            }
            ++removedElements;
        }
    }

    for(int i = 0; i < removedElements; ++i) {
        // This segfaults
        //free(array[arrayLength - 1 - i]);
    }
}

int main() {
    const char *string = "Hello World!";
    // Allocate enough memory for worst case scenario: Every character is unique
    symbol *symbols = (symbol *) calloc(sizeof(symbol), strlen(string));

    if(!symbols) {
        printf("Out of memory when allocating symbols\n");
        return 1;
    }

    getSymbols(string, symbols);

    getSymbolsFrequency(string, symbols, symbols);

    // At first holds full array length
    unsigned long remainingSymbolsArrayLength = getSymbolsLen(symbols);

    sortSymbolArray(symbols, remainingSymbolsArrayLength);

    struct node **leafNodes = calloc(remainingSymbolsArrayLength, sizeof(struct node *));

    if (!leafNodes) {
        printf("Out of memory when allocating leaf nodes\n");
        free(symbols);
        return 1;
    }

    for (int i = 0; i < remainingSymbolsArrayLength; ++i) {
        leafNodes[i] = newLeafNode(symbols[i]);
        if(!leafNodes[i]) {
            printf("Out of memory when creating leaf nodes\n");
            free(leafNodes);
            free(symbols);
            return 1;
        }
    }
    free(symbols);

    for (unsigned long i = 0; i < remainingSymbolsArrayLength; ++i) {
        if (i % 2 == 0 && i > 0) {
            struct node *newNode = combineNode(leafNodes[i - 2], leafNodes[i - 1]);
            removeElementsFromNodeArray(leafNodes, 2, getNodeArrayLength(leafNodes));
            remainingSymbolsArrayLength -= 2;
            leafNodes = addNodeToArray(newNode, leafNodes, getNodeArrayLength(leafNodes));
        }
    }


    free(leafNodes);
    return 0;
}
