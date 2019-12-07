#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
    int data;
    struct Node_s *left, *right;
} Tree;

int height(Tree *root) {
    int height_left, height_right;
    if (root == NULL)
        return -1;
    height_left = height(root->left);
    height_right = height(root->right);
    if (height_left >= height_right)
        return height_left + 1;
    else
        return height_right + 1;
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
    printf("%d", height(root));
    free_tree(root);
    return 0;
}