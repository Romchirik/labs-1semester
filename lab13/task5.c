#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	int data;
	struct List* next;
	struct List* prev;
} list;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	list *p, *last, *pre;
	list *head;
	scanf("%d%d", &n, &k);
	p = malloc(sizeof(list));
	p->data = 1;
	p->prev = NULL;
	pre = p;
	head = p;
	if (n < 2) {
		printf("%d", k);
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		p = malloc(sizeof(list));
		p->data = i;
		p->prev = pre;
		pre->next = p;
		pre = p;
	}
	last = p;
	p->next = head;
	head->prev = last;
	p = head;
	while (head != last) {
		for (int i = 1; i < k; i++) {
			p = p->next;
		}
		list *b = p;
		if (p == head)
			head = p->next;
		if (p == last)
			last = p->prev;
		(p->prev)->next = p->next;
		(p->next)->prev = p->prev;
		p = p->next;
		free(b);
	}
	printf("%d", head->data);
	free(head);
	scanf("%d", &n);
	return 0;
}
