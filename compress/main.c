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
#include <stdlib.h>
#include "../include/node.h"
#include "../include/symbol.h"
#include "../include/encoding.h"
#include "../include/utility.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("No file provided. Exiting...\n");
        return 1;
    }

    char *string;
    FILE *file = fopen(argv[1], "r");

    if (file) {
        fseek(file, 0, SEEK_END);
        long length = ftell(file);
        fseek(file, 0, SEEK_SET);
        string = (char *) malloc(length);
        if (string) {
            fread(string, 1, length, file);
        }
        fclose(file);
        string[length] = (char) 1;
    }

    // Allocate enough memory for worst case scenario: Every character is unique
    symbol *symbols = (symbol *) calloc(strlen(string), sizeof(symbol));

    if(!symbols) {
        printf("Out of memory when allocating symbols\n");
        return 1;
    }

    getSymbols(string, symbols);

    getSymbolsFrequency(string, symbols, symbols);
    // At first holds full array length
    uint32_t remainingSymbolsArrayLength = getSymbolsLen(symbols);

    sortSymbolArray(symbols, remainingSymbolsArrayLength);

    struct node **leafNodes = calloc(remainingSymbolsArrayLength+1, sizeof(struct node *));

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

    while(getNodeArrayLength(leafNodes) >= 2) {
        sortNodeArray(leafNodes, getNodeArrayLength(leafNodes));
        struct node *leftNode = leafNodes[0];
        struct node *rightNode = leafNodes[1];
        removeFirstElementFromNodeArray(leafNodes, getNodeArrayLength(leafNodes));
        removeFirstElementFromNodeArray(leafNodes, getNodeArrayLength(leafNodes));
        struct node *combinedNode = combineNode(leftNode, rightNode);
        appendNodeToArray(combinedNode, leafNodes);
    }

    generateAndPrintEncoding(leafNodes[0], symbols, leafNodes[0]->data.encoding, 0);

    int length = 0;
    int *encodedString = generateEncodedString(string, symbols, &length);

    char *outputFileName = malloc(strlen(argv[1]) + 6); // File name, extension and NULL
    sprintf(outputFileName, "%s.huff", argv[1]);
    FILE *outputFile = fopen(outputFileName, "wb+");

    writeDictionaryToFile(symbols, file);
    writeEncodedStringToFile(encodedString, outputFile, length);


    fclose(outputFile);
    free(string);
    free(encodedString);
    free(outputFileName);
    free(symbols);
    free(leafNodes);
    return 0;
}