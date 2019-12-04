#include <stdio.h>
#include <stdlib.h>

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

Node *cut_head(Node *head) {
    Node *tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

void cut_node(Node *previous_node) {
    Node *tmp = previous_node->next;
    previous_node->next = tmp->next;
    free(tmp);
}

Node *delete_previous(Node *head, int el) {
    Node *first = head;
    Node *previous = NULL;


    while (first->next != NULL){
        if (first->next->data == el) {
            if (previous == NULL){
                first = head->next;
                head = cut_head(head);
                previous = head;
                continue;
            } else {
                cut_node(previous);
                first = previous->next;
                continue;
            }
        }
        previous = first;
        first = first->next;
    }
    return head;
}

int main(void) {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int node_data, target;
    scanf("%d", &target);
    Node *head = NULL;

    while (scanf("%d", &node_data) == 1) {
        Node *node = (Node *) malloc(sizeof(Node));
        node->data = node_data;
        node->next = head;
        head = node;
    }

    head = delete_previous(head, target);
    print_list(head);
    list_free(head);
}