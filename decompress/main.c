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
#include <stdlib.h>
#include <string.h>
#include "../include/symbol.h"
#include "../include/utility.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("No compressed file provided. Exiting...\n");
        return 1;
    }

    FILE *compressedFile = fopen(argv[1], "rb");
    if (!compressedFile) {
        printf("Couldn't open input file.\n");
        return 1;
    }
    symbol *dictionary = getDictionaryFromFile(compressedFile);

    int offset = (getSymbolsLen(dictionary) * sizeof(symbol)) + sizeof(uint32_t);
    size_t encodedStringSize = 0;
    uint8_t *encodedString = getEncodedStringFromFile(compressedFile, offset, &encodedStringSize);
    fclose(compressedFile);

    char *plainText = decodeString(encodedString, encodedStringSize, dictionary);

    char *outputFileName = calloc(strlen(argv[1]) + 1, sizeof(char));

    for (int i = 0; i < strlen(argv[1]) - 5; ++i) {
        outputFileName[i] = argv[1][i];
    }

    FILE *outputFile = fopen(outputFileName, "w+");
    if (!outputFile) {
        printf("Couldn't create/open output file!\n");
        free(outputFileName);
        free(plainText);
        free(encodedString);
        free(dictionary);
        return 1;
    }
    fprintf(outputFile, "%s", plainText);

    free(outputFileName);
    free(plainText);
    fclose(outputFile);
    free(encodedString);
    free(dictionary);
    return 0;
}
