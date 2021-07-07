
//
// Created by kosmas on 6/7/21.
//

#ifndef HUFFMANCODING_SYMBOL_H
#define HUFFMANCODING_SYMBOL_H

typedef struct {
    char character;
    int frequency;
}symbol;

void getSymbols(const char *string, symbol *output);
void getSymbolsFrequency(const char *string, symbol *symbols, symbol *output);
unsigned long getSymbolsLen(const symbol *symbols);
void swapSymbols(symbol *operand1, symbol *operand2);
// This sorts in ascending frequency order following a selection sort approach
void sortSymbolArray(symbol *array, unsigned long arrayLength);

#endif //HUFFMANCODING_SYMBOL_H
