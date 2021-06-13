
#ifndef TREESFORTICKETS_HEADER_H
#define TREESFORTICKETS_HEADER_H

#endif //TREESFORTICKETS_HEADER_H

struct BinaryTree
{
    int item;
    struct BinaryTree* left;
    struct BinaryTree* right;
    struct BinaryTree* parent;
};

struct BinaryTree* rootInitialization(struct BinaryTree* root, int data);
struct BinaryTree* addNode(struct BinaryTree* root, int data);
struct BinaryTree* deleteItem(struct BinaryTree* root, int compareNumber);
void preorder(struct BinaryTree *root);
void see_1(struct BinaryTree *root);