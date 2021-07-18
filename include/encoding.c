//
// Created by kosmas on 18/7/21.
//

#include "encoding.h"

#include <stdio.h>
#include "node.h"

void printEncoding(int *encoding, int encodingLength) {
    int i;
    for (i = 0; i < encodingLength; ++i) {
        printf("%d", encoding[i]);
    }

    printf("\n");
}

void generateAndPrintEncoding(struct node *root, int *encoding, int start) {
    if (root->left) {
        encoding[start] = 0;
        generateAndPrintEncoding(root->left, encoding, start + 1);
    }

    if (root->right) {
        encoding[start] = 1;
        generateAndPrintEncoding(root->right, encoding, start + 1);
    }

    // If this is a leaf node
    if (root->data.character != (char) 0) {
        printf("%c: ", root->data.character);
        printEncoding(encoding, start);
    }
}
