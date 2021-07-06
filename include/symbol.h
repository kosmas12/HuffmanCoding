
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

#endif //HUFFMANCODING_SYMBOL_H
