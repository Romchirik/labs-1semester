#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	int data;
	struct List* next;
} list;

list* mergeList(list *h1, list *h2){
	list *newHead;
	list *p;
	list *l1, *l2;
	if (h1->data < h2->data) {
		newHead = h1;
		h1 = h1->next;
	}
	else {
		newHead = h2;
		h2 = h2->next;
	}
	l1 = newHead;
	while (h1 != NULL && h2 != NULL) {
		if (h1->data < h2->data) {
			p = h1;
			h1 = h1->next;
		}
		else {
			p = h2;
			h2 = h2->next;
		}
		l1->next = p;
		l1 = l1->next;
	}
	if (h1 == NULL) {
		while (h2 != NULL) {
			l1->next = h2;
			h2 = h2->next;
			l1 = l1->next;
		}
	}
	else {
		while (h1 != NULL) {
			l1->next = h1;
			h1 = h1->next;
			l1 = l1->next;
		}
	}
	l1->next = NULL;
	return newHead;
}

list* reverseList(list* head) {
	list* prev = NULL;
	list *cur = head, *next = head;
	while (next != NULL) {
		next = next->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	list *p, *h1, *h2;
	scanf("%d%d", &n, &m);
	p = malloc(sizeof(list));
	scanf("%d", &p->data);
	h1 = p;
	list *pre = p;
	for (int i = 1; i < n; i++) {
		p = malloc(sizeof(list));
		scanf("%d", &p->data);
		pre->next = p;
		pre = p;
	}
	p->next = NULL;

	p = malloc(sizeof(list));
	scanf("%d", &p->data);
	pre = p;
	h2 = p;
	for (int i = 1; i < m; i++) {
		p = malloc(sizeof(list));
		scanf("%d", &p->data);
		pre->next = p;
		pre = p;
	}
	p->next = NULL;
	p = mergeList(h1, h2);
	p = reverseList(p);
	while (p != NULL) {
		printf("%d ", p->data);
		list *tmp = p;
		p = p->next;
		free(tmp);
	}
	return 0;
}
