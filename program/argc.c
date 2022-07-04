#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

void print_tree(node *root);
void free_tree(node *root);

int main()
{
    node *tree = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
    return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    print_tree(tree);

    free_tree(tree);
    return 0;

}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->right);
    printf("%i\n", root->number);
    print_tree(root->left);
}
void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
}
