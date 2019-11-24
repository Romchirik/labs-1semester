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

  while (scanf("%d ", &num) == 1)
  {
    Node *node = malloc(sizeof(Node));
    node->val = num;
    node->next = head;
    head = node;
  }

  int cnt = 0;

  while (head)
  {
    if (head->val < 0 && head->val % 7 == 0)
    {
      cnt++;
    }

    Node *tmp = head->next;
    free(head);
    head = tmp;
  }

  printf("%d", cnt);

  return 0;
}