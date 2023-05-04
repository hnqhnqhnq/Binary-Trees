#include <stdio.h>
#include "binary_tree.h"

int main() {
    NodeT *root;
    FILE *f = fopen("BinaryTree.txt", "r");

    if (!f) {
        printf("Couldnt't read from file!\n");
        return -1;
    }

    root = createBinTreeFile(f);

    Preorder(root);
    printf("\n");

    Inorder(root);
    printf("\n");

    Postorder(root);
    printf("\n");

    int leaf = leafNode(root);
    printf("%d", leaf);
    printf("\n");

    printLeafNode(root);
    printf("\n");

    int in = inNodes(root);
    printf("%d", in);
    printf("\n");

    printInNodes(root);
    printf("\n");

    int height = Height(root);
    printf("%d", height);
    printf("\n");

    printf("%p\n", Search(root, 1));
    printf("%p\n", Search(root, 2));
    printf("%p\n", Search(root, 3));
    printf("%p\n", Search(root, 4));
    printf("%p\n", Search(root, 5));
    printf("%p\n", Search(root, 6));
    printf("%p\n", Search(root, 7));
    printf("%p\n", Search(root, 8));
    printf("%p\n", Search(root, 9));

    return 0;
}
