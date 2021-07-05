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

struct node *newNode(int data) {
    struct node *node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node *insertNode(struct node *node, int data) {
    // If there's no tree, create one
    if(node == NULL) {
        return newNode(0);
    }

    if(data <= node->data) {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }

    return node;
}

int lookupData(struct node *node, int targetData) {
    if(node == NULL) {
        return 0;
    }
    else {
        if (targetData == node->data) {
            return 1;
        }
        if (targetData < node->data) {
            return lookupData(node->left, targetData);
        }
        else {
            return lookupData(node->right, targetData);
        }
    }
}
