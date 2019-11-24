#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *next;
} Node;

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int num;

  Node *head = NULL;
  Node *tail = NULL;

  while (scanf("%d ", &num) == 1)
  {
    Node *node = malloc(sizeof(Node));
    node->val = num;
    node->next = NULL;

    if (head == NULL)
    {
      head = tail = node;
    }
    else
    {
      tail->next = node;
      tail = node;
    }
  }

  int sum = 0;
  int cnt = 0;

  while (head != NULL)
  {
    sum += head->val;
    cnt++;

    Node *tmp = head->next;
    free(head);
    head = tmp;
  }

  printf("%d", sum / cnt);

  return 0;
}