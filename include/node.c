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

void removeFirstElementFromNodeArray(struct node **array, unsigned long arrayLength) {
    for (int i = 0; i < arrayLength-1; i++) {
        array[i] = array[i+1];
    }
    array[arrayLength-1] = NULL;
}

void appendNodeToArray(struct node *node, struct node **array) {
    int i = 0;
    while(array[i] != 0) i++;
    array[i] = node;
    array[i+1] = 0;
}

struct node **sortNodeArray(struct node **array, unsigned long arrayLength) {
    unsigned long i, j;

    for(i = 0; i < arrayLength; i++) {
        for(j = i + 1; j < arrayLength; j++) {
            if(array[j]->data.frequency < array[i]->data.frequency) {
                struct node *temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return array;
}
