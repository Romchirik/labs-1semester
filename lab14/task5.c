#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_s {
    char data[100];
    struct Node_s *left, *right;
} Tree;

void free_tree(Tree *root) {
    if (!root)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root->data);
    free(root);
}

void print_tree_infixed(Tree *root) {
    if (!root)
        return;
    print_tree_infixed(root->left);
    printf("%s\n", root->data);
    print_tree_infixed(root->right);
}

Tree *add_leaf(Tree *root, char *value) {
    if (root == NULL) {
        root = (Tree *) malloc(sizeof(Tree));
        strcpy(root->data, value);
        root->right = NULL;
        root->left = NULL;
        return root;
    }
    if (strcmp(root->data, value) == 0)
        return root;
    if (strcmp(root->data, value) > 0)
        root->left = add_leaf(root->left, value);
    if (strcmp(root->data, value) < 0)
        root->right = add_leaf(root->right, value);
    return root;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Tree *root = NULL;
    int level;
    char value[100];
    scanf("%d", &level);
    while (scanf("%s", value) == 1) {
        root = add_leaf(root, value);
    }
    print_tree_infixed(root);
    
    return 0;
}