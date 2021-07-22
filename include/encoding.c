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
#include "encoding.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"
#include "utility.h"

void printEncoding(uint8_t encoding[], int encodingLength) {
    int i;
    for (i = 0; i < encodingLength; ++i) {
        printf("%d", encoding[i]);
    }

    printf("\n");
}

void generateAndPrintEncoding(struct node *root, symbol symbols[], uint8_t encoding[], int start) {
    if (root->left) {
        encoding[start] = 0;
        generateAndPrintEncoding(root->left, symbols, encoding, start + 1);
    }

    if (root->right) {
        encoding[start] = 1;
        generateAndPrintEncoding(root->right, symbols, encoding, start + 1);
    }

    // If this is a leaf node
    if (root->data.character != (char) 0) {
        printf("%c: ", root->data.character);
        printEncoding(encoding, start);

        for (int i = 0; i < getSymbolsLen(symbols); ++i) {
            if(symbols[i].character == root->data.character) {
                symbols[i].encodingLength = start;
                for (int j = 0; j < start; ++j) {
                    symbols[i].encoding[j] = encoding[j];
                }
                break;
            }
        }

    }
}

int *generateEncodedString(const char *string, const symbol symbols[], int *numBitsWrittenOutput) {
    int *encodedString = (int *) calloc(strlen(string) * 4, sizeof(int));

    int numBitsWritten = 0;

    for (int i = 0; i < strlen(string); ++i) {
        for (int j = 0; j < getSymbolsLen(symbols); ++j) {
            if (string[i] == symbols[j].character) {
                int k = 0;
                while (k < symbols[j].encodingLength) {
                    encodedString[numBitsWritten++] = symbols[j].encoding[k++];
                }
                break;
            }
        }
    }

    int i = 0;
    while (i < numBitsWritten) {
        printf("%d", encodedString[i++]);
    }
    printf("\n");

    *numBitsWrittenOutput = numBitsWritten;
    return encodedString;

}

char translateEncoding(const uint8_t encoding[], const symbol dictionary[]) {
    int encodingLength = 1;

    for (int i = 0; i < getSymbolsLen(dictionary); ++i) {
        if (dictionary[i].encoding == encoding) {
            return dictionary[i].character;
        }
    }
    return (char) 0;
}

char *decodeString(const uint8_t encodedString[], const size_t encodedStringSize, const symbol dictionary[]) {
    // sizeof(char) can be replaced with 1 in most systems but not all
    char *decodedString = calloc(encodedStringSize, sizeof(char));

    int decodedBits = 0;

    uint8_t *encodedStringBits = calloc(encodedStringSize, sizeof(uint8_t) * 8);

    int encodedBits = 0;
    for (int i = 0; i < encodedStringSize; i++) {
        for (int j = 0; j < 8; ++j) {
            encodedStringBits[encodedBits++] = getBit(encodedString[i], j);
        }
    }

    for (int i = 0; i < encodedStringSize; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (decodedString[i] != (char) 0) {
                decodedBits += j;
                break;
            }
        }
    }

    return decodedString;

}

