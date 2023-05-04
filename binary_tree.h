#pragma once

#include <stdio.h>

typedef struct NodeT {
    int id;
    struct NodeT *left;
    struct NodeT *right;
} NodeT;

NodeT *createNode();

NodeT *createBinTreeFile(FILE *f);

void Preorder(NodeT *root);

void Inorder(NodeT *root);

void Postorder(NodeT *root);

int leafNode(NodeT *root);

void printLeafNode(NodeT *root);

int inNodes(NodeT *root);

void printInNodes(NodeT *root);

int Height(NodeT *root);

NodeT *Search(NodeT *root, int key);


