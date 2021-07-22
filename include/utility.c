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

#include "utility.h"

void setBit(uint8_t *value, uint8_t bitToSet, int set) {
    if (set) {
        *value |= 1UL << bitToSet;
    }
    else {
        *value &= ~(1UL << bitToSet);
    }
}

uint8_t getBit(uint8_t value, uint8_t bitToGet) {
    return (uint8_t) (value & ( 1 << bitToGet )) >> bitToGet;
}

void writeDictionaryToFile(const symbol dictionary[], FILE *file) {
    const uint32_t dictionarySize = getSymbolsLen(dictionary) * sizeof(symbol);

    // sizeof(uint32_t) can be replaced by 4 but some implementations might not adhere to standard
    fwrite(&dictionarySize, sizeof(uint32_t), 1, file);

    fwrite(dictionary, dictionarySize, 1, file);
}

void writeEncodedStringToFile(const int encodedString[], FILE *file, int length) {
    static int bytesWritten = 1;

    while (length > 0) {
        uint8_t byteToWrite = 0;
        for (int i = 0; i < 8; ++i) {
            if (length > 0) {
                setBit(&byteToWrite, i, encodedString[i * bytesWritten] == 1);
                --length;
            }
            else {
                // If all the bytes were written before the next while iteration
                break;
            }
        }
        // sizeof(uint8_t) can be replaced with 1 in most systems but some implementations might not adhere to standard
        fwrite(&byteToWrite, sizeof(uint8_t), 1, file);
        ++bytesWritten;
        byteToWrite = 0;
    }
}

symbol *getDictionaryFromFile(FILE *file) {
    uint32_t dictionarySize = 0;
    fread(&dictionarySize, sizeof(uint32_t), 1, file);

    symbol *dictionary = (symbol *) malloc(dictionarySize);
    fread(dictionary, dictionarySize, 1, file);

    return dictionary;
}

uint8_t *getEncodedStringFromFile(FILE *file, uint32_t offsetFromStart, size_t *encodedStringSizeOutput) {
    fseek(file, 0, SEEK_END);
    const size_t encodedStringSize = ftell(file) - offsetFromStart;
    fseek(file, 0, SEEK_SET);
    // sizeof(uint8_t) can be replaced with 1 in most systems but some implementations might not adhere to standard
    uint8_t *encodedString = (uint8_t *) calloc(encodedStringSize, sizeof(uint8_t));

    int i = 0;
    while (!feof(file)) {
        fread(&encodedString[i++], sizeof(uint8_t), 1, file);
    }
    *encodedStringSizeOutput = encodedStringSize;
    return encodedString;
}
