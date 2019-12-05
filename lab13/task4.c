#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
    struct Node_s *prev, *next;
    void *value;
} Node;

// List –- вспомогательный узел, являющийся головой списка
typedef Node List;

// инициализирует поля структуры *list значениями для пустого списка
void initList(List *list);

// создаёт новый узел со значением ptr и вставляет его после узла node
// возвращает указатель на созданный узел
Node* addAfter(Node *node, void *ptr);

// создаёт новый узел со значением ptr и вставляет его перед узлом node
// возвращает указатель на созданный узел
Node* addBefore(Node *node, void *ptr);

// удаляет заданный узел, возвращая значение, которое в нём лежало
void* erase(Node *node);

void initList(List *list)
{
    list->value = NULL;
    list->prev = list;
    list->next = list;
}

Node* addAfter(Node *node, void *ptr)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->value = ptr;

    new_node->prev = node;
    new_node->next = node->next;
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;

    return new_node;
}

Node* addBefore(Node *node, void *ptr)
{
    return addAfter(node->prev, ptr);
}

void* erase(Node *node)
{
    void *res = node->value;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    free(node);

    return res;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t_count;
    scanf("%d", &t_count);

    for (int t = 0; t < t_count; ++t)
    {
        int q;
        scanf("%d", &q);

        List *list = malloc(sizeof(List));
        initList(list);

        Node* arr[100001];
        arr[0] = list;
        int arr_len = 1;

        for (int i = 0; i < q; ++i)
        {
            int operation_id, index;
            scanf("%d %d", &operation_id, &index);
            index++;

            Node* node = arr[index];

            switch (operation_id)
            {
                case 0:
                {
                    erase(node);
                    break;
                }
                case 1:
                {
                    int *val = malloc(sizeof(int));
                    scanf("%d", val);
                    arr[arr_len] = addAfter(node, val);
                    arr_len++;
                    break;
                }
                case -1:
                {
                    int *val = malloc(sizeof(int));
                    scanf("%d", val);
                    arr[arr_len] = addBefore(node, val);
                    arr_len++;
                    break;
                }
                default:
                    break;
            }
        }


        Node *start = list->next;
        while (start->value != NULL)
        {
            printf("%d\n", *(int*)start->value);
            start = start->next;
        }
        printf("===\n");
    }

    return 0;
}