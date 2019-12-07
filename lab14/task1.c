#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
    int data;
    struct Node_s *left, *right;
} Tree;

void print_tree_directly(Tree *root) {
    if (!root)
        return;
    printf("%d ", root->data);
    print_tree_directly(root->left);
    print_tree_directly(root->right);
}

void print_tree_reversed(Tree *root) {
    if (!root)
        return;
    print_tree_reversed(root->left);
    print_tree_reversed(root->right);
    printf("%d ", root->data);
}

void free_tree(Tree *root) {
    if (!root)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

Tree *add_leaf(Tree *root, int value) {
    if (root == NULL) {
        root = (Tree *) malloc(sizeof(Tree));
        root->right = NULL;
        root->left = NULL;
        root->data = value;
        return root;
    }
    if (root->data == value)
        return root;
    if (root->data > value)
        root->left = add_leaf(root->left, value);
    if (root->data < value)
        root->right = add_leaf(root->right, value);
    return root;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Tree *root = NULL;
    int value;
    while (scanf("%d", &value) == 1) {
        root = add_leaf(root, value);
    }
    print_tree_directly(root);
    printf("\n");
    print_tree_reversed(root);
    printf("\n");
    free_tree(root);
    return 0;
}