#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_s {
    int data;
    struct Node_s *next;
} Node;

void list_free(Node *first) {
    while (first) {
        Node *buffer = first->next;
        free(first);
        first = buffer;
    }
}

void print_list(Node *first) {
    while (first) {
        printf("%d ", first->data);
        first = first->next;
    }
}

void cut_node(Node *previous_node) {
    Node *death_node = previous_node->next;
    previous_node->next = death_node->next;
    free(death_node);
}

int main(void) {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int next_data;
    Node *first = NULL;
    Node *last = NULL;

    while (scanf("%d", &next_data) == 1) {
        Node *node = malloc(sizeof(Node));
        node->next = NULL;
        node->data = next_data;
        if (first == NULL) {
            first = node;
            last = node;
        } else {
            last->next = node;
            last = node;
        }
    }

    int previous_data;
    Node *previous_node;
    Node *head = first;

    while (first != NULL) {
        if (first->next != NULL) {
            if (first->data == first->next->data) {
                cut_node(first);
                continue;
            }
        }
        first = first->next;
    }
    print_list(head);
    list_free(head);
}