
#include "Header.h"
#include <stdlib.h>
#include <stdio.h>

struct BinaryTree* rootInitialization(struct BinaryTree* root, int data)
{
    struct BinaryTree* temp = (struct BinaryTree*)calloc(1, sizeof(struct BinaryTree));
    temp ->item = data;
    temp ->left = NULL;
    temp ->right = NULL;
    root = temp;
    return root;
}

struct BinaryTree* addNode(struct BinaryTree* root, int data)
{
    struct BinaryTree* copyOfRoot = root;
    struct BinaryTree* copyOfParent = NULL;
    struct BinaryTree* temp = (struct BinaryTree*)calloc(1,sizeof(struct BinaryTree));
    temp->item = data;
    while (copyOfRoot != NULL)
    {
        copyOfParent = copyOfRoot;
        if (copyOfRoot->item < data)
        {
            copyOfRoot = copyOfRoot->right;
        }
        else
        {
            copyOfRoot = copyOfRoot->left;
        }
    }

    temp->parent = copyOfParent;
    temp->left = NULL;
    temp-> right = NULL;
    if (copyOfParent->item < data)
    {
        copyOfParent->right = temp;
    }
    else
    {
        copyOfParent->left = temp;
    }
    return root;
}

//void preorder(struct BinaryTree *root)
//{
//    if (root == NULL)
//        return;
//    if (root ->
//        printf("%d ", root -> item);
//    preorder(root -> left);
//    preorder(root -> right);
//}

void see_1(struct BinaryTree *root)
{
    if (root)
    {
        if (root->left)
        {
            see_1(root->left);
        }
        if (root->right)
        {
            see_1(root->right);
        }
        printf("%d ", root -> item);

    }
}

struct BinaryTree* deleteItem(struct BinaryTree* root, int compareNumber)
{

}
struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

        // If the key to be deleted
        // is greater than the root's
        // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
        // if key is same as root's key,
        // then This is the node
        // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}