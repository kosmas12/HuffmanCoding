//
// Created by kosmas on 18/7/21.
//

#ifndef HUFFMANCODING_ENCODING_H
#define HUFFMANCODING_ENCODING_H

#include "node.h"

void printEncoding(int *encoding, int encodingLength);
void generateAndPrintEncoding(struct node *root, int *encoding, int start);

#endif //HUFFMANCODING_ENCODING_H
