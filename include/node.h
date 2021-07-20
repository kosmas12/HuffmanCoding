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

#ifndef HUFFMANCODING_NODE_H
#define HUFFMANCODING_NODE_H

#include "symbol.h"
#include <stdint.h>

struct node {
    symbol data;
    struct node *left;
    struct node *right;
};

struct node *newLeafNode(symbol data);
struct node *newInternalNode(int data);
struct node *combineNode(struct node *leftNode, struct node *rightNode);
int lookupData(struct node *node, symbol targetData);
uint32_t getNodeArrayLength(struct node **array);
void removeFirstElementFromNodeArray(struct node **array, uint32_t arrayLength);
void appendNodeToArray(struct node *node, struct node **array);
struct node **sortNodeArray(struct node **array, uint32_t arrayLength);

#endif //HUFFMANCODING_NODE_H
