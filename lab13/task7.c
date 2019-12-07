#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000001
#define STRING_MAX_LEN 8

typedef struct node
{
    char *val;
    struct node *prev;
    struct node *next;
} Node;

void initList(Node **list)
{
    *list = malloc(sizeof(Node));

    (*list)->val = NULL;
    (*list)->prev = (*list);
    (*list)->next = (*list);
}

Node *addAfter(Node *node, void *ptr)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->val = ptr;

    new_node->prev = node;
    new_node->next = node->next;
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;

    return new_node;
}

Node *list_arr[TABLE_SIZE] = {NULL};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        int k;
        char *str = malloc(STRING_MAX_LEN * sizeof(char));
        scanf("%d %s\n", &k, str);

        if (!list_arr[k])
        {
            initList(&list_arr[k]);
        }

        Node *el = list_arr[k]->prev;
        Node *new_node = addAfter(el, str);
        list_arr[k] = new_node->next;
    }

    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        if (!list_arr[i])
        {
            continue;
        }

        for (Node *start = list_arr[i]->next; start->val != NULL; start = start->next)
        {
            printf("%d %s\n", i, (char *)start->val);
        }
    }

    return 0;
}