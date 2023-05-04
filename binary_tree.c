#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

int maxNumbers(int a, int b) {
    if (a > b)
        return a;

    if (b > a)
        return b;

    return a;
}

NodeT *createNode() {
    NodeT *node = malloc(sizeof(NodeT));

    if (node == NULL) {
        printf("Couldn't allocate memory!\n");
        return NULL;
    }

    node->id = 0;
    node->left = NULL;
    node->right = NULL;
}

NodeT *createBinTreeFile(FILE *f) {
    NodeT *node;
    int value;

    fscanf(f, "%d", &value);

    if (value == 0)
        return NULL;
    else {
        node = createNode();
        node->id = value;
        node->left = createBinTreeFile(f);
        node->right = createBinTreeFile(f);
    }

    return node;
}

void Preorder(NodeT *root) {
    if (root != NULL) {
        printf("%d ", root->id);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(NodeT *root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%d ", root->id);
        Inorder(root->right);
    }
}

void Postorder(NodeT *root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->id);
    }
}

int leafNode(NodeT *root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL & root->right == NULL)
        return 1;

    return leafNode(root->left) + leafNode(root->right);
}

void printLeafNode(NodeT *root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->id);

    printLeafNode(root->left);
    printLeafNode(root->right);
}

int inNodes(NodeT *root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 0;

    return 1 + inNodes(root->left) + inNodes(root->right);
}

void printInNodes(NodeT *root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    printf("%d ", root->id);
    printInNodes(root->left);
    printInNodes(root->right);
}

int Height(NodeT *root) {
    if (root == NULL)
        return -1;

    return 1 + maxNumbers(Height(root->left), Height(root->right));
}

NodeT *Search(NodeT *root, int key) {
    if (root == NULL)
        return NULL;

    if (root->id == key)
        return root;

    NodeT *left = Search(root->left, key);

    if (left != NULL)
        return left;

    NodeT *right = Search(root->right, key);

    if (right != NULL)
        return right;
}

