#include <stdio.h>
#include "Header.h"
int main()
{
    struct BinaryTree* root;
    root = rootInitialization(root, 10);
    root = addNode(root, 7);
    root = addNode(root, 12);
    root = addNode(root, 6);
    root = addNode(root, 9);
    root = addNode(root, 11);
    root = addNode(root, 14);
//    root = deleteItem(root, 9);

    see_1(root);
    printf("\n");
    root = deleteItem(root, 9);
    see_1(root);

    return 0;
}
