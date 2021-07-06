//
// Created by kosmas on 6/7/21.
//

#include <string.h>
#include <stdint.h>
#include "symbol.h"

void getSymbols(const char *string, symbol *output) {
    char curSymbol = '\0';
    unsigned long numFoundSymbols = 0;
    unsigned long numIterations = strlen(string);
    for (unsigned long i = 0; i < numIterations; ++i) {
        curSymbol = string[i];
        for (unsigned long j = 0; j < numIterations; ++j) {
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
    int symbolslen = getSymbolsLen(symbols);

    for (unsigned long i = 0; i < symbolslen; ++i) {
        for (unsigned long j = 0; j < strlen(string); ++j) {
            if (symbols[i].character == string[j]) {
                ++output[i].frequency;
            }
        }
    }
}

unsigned long getSymbolsLen(const symbol *symbols) {
    unsigned long symbolslen = 0;

    while (symbols[symbolslen].character) {
        ++symbolslen;
    };
    return symbolslen;
}
