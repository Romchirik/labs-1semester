#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	float val;
	int next;
} Node;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, f;
	scanf("%d %d", &n, &f);

	Node *arr = malloc(n * sizeof(Node));

	for (int i = 0; i < n; ++i)
	{
		scanf("%f %d", &arr[i].val, &arr[i].next);
	}

	while (f != -1)
	{
		printf("%.3f\n", arr[f].val);
		f = arr[f].next;
	}

	return 0;
}