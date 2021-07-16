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

#include "node.h"
#include <malloc.h>

struct node *newLeafNode(symbol data) {
    struct node *node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node *newInternalNode(int data) {
    struct node *node = malloc(sizeof(struct node));
    node->data.character = (char) 0;
    node->data.frequency = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node *combineNode(struct node *leftNode, struct node *rightNode) {
    struct node *combinedNode = newInternalNode(leftNode->data.frequency + rightNode->data.frequency);

    combinedNode->left = leftNode;
    combinedNode->right = rightNode;

    return combinedNode;
}

int lookupData(struct node *node, symbol targetData) {
    if(node == NULL) {
        return 0;
    }
    else {
        if (targetData.frequency == node->data.frequency) {
            return 1;
        }
        if (targetData.frequency < node->data.frequency) {
            return lookupData(node->left, targetData);
        }
        else {
            return lookupData(node->right, targetData);
        }
    }
}

unsigned long getNodeArrayLength(struct node **array) {
    unsigned long length = 0;

    while (array[length]) {
        ++length;
    }
    return length;
}

struct node **addNodeToArray(struct node *node, struct node **array, unsigned long arrayLength) {
    array = realloc(array, sizeof(struct node *) * (arrayLength + 1) * 8);
    array[arrayLength] = node;
    return sortNodeArray(array, getNodeArrayLength(array));
}

void swapNodes(struct node *operand1, struct node *operand2) {
    struct node *temp = operand1;
    operand1 = operand2;
    operand2 = temp;
}

struct node **sortNodeArray(struct node **array, unsigned long arrayLength) {
    unsigned long minimumFrequencyIndex;

    for (unsigned long i = 0; i < arrayLength - 1; i++) {
        // Find symbol with minimum frequency
        minimumFrequencyIndex = i;
        for (unsigned long j = 0; j < arrayLength; j++) {
            if (array[j]->data.frequency < array[minimumFrequencyIndex]->data.frequency) {
                minimumFrequencyIndex = j;
            }
        }

        swapNodes(array[minimumFrequencyIndex], array[i]);
    }
    return array;
}
