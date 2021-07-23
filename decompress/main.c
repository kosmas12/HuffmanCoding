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

    uint32_t offset = (getSymbolsLen(dictionary) * sizeof(symbol) + sizeof(uint32_t));
    size_t encodedStringSize = 0;
    uint8_t *encodedString = getEncodedStringFromFile(compressedFile, offset, &encodedStringSize);

    char *plainText = decodeString(encodedString, encodedStringSize, dictionary);

    printf("%s\n", plainText);

    free(plainText);
    fclose(compressedFile);
    free(encodedString);
    free(dictionary);
    return 0;
}
