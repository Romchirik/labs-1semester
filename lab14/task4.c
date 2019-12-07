#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
    int data;
    struct Node_s *left, *right;
} Tree;

int count_nodes_on_level(Tree *root, int level) {
    if (root == NULL)
        return 0;
    if (level == 0)
        return 1;
    return count_nodes_on_level(root->left, level - 1) + count_nodes_on_level(root->right, level - 1);

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
    int value, level;
    scanf("%d", &level);
    while (scanf("%d", &value) == 1) {
        root = add_leaf(root, value);
    }
    printf("%d", count_nodes_on_level(root, level));
    free_tree(root);
    return 0;
}