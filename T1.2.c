//-------Проход по дереву рекурсивно, вывод по возрастанию.

typedef struct tree
{
    int key;
    struct tree* left;
    struct tree* right;
    struct tree* parent;
} node;

void preorder(node* root)
{
    if (root == NULL)
        return;
    if (root->key)
        printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}