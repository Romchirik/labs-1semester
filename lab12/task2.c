#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char val[8];
	int next;
} Node;

void insertInList(Node *arr, int *length, int *f, int index, char *val)
{
	strcpy(arr[*length].val, val);

	if (index == -1)
	{
		arr[*length].next = *f;
		*f = *length;
	}
	else
	{
		arr[*length].next = arr[index].next;
		arr[index].next = *length;
	}

	printf("%d\n", *length);
	(*length)++;
}

void removeFromList(Node *arr, int *length, int *f, int index)
{
	if (index == -1)
	{
		printf("%s\n", arr[*f].val);
		*f = arr[*f].next;
	}
	else
	{
		printf("%s\n", arr[arr[index].next].val);
		arr[index].next = arr[arr[index].next].next;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t_count;
	scanf("%d", &t_count);

	for (int t = 0; t < t_count; ++t)
	{
		int n, f, q;
		scanf("%d %d %d", &n, &f, &q);

		Node arr[200001];

		for (int i = 0; i < n; ++i)
		{
			scanf("%s %d", &arr[i].val, &arr[i].next);
		}

		for (int i = 0; i < q; ++i)
		{
			int operation_id, index;
			scanf("%d %d", &operation_id, &index);

			switch (operation_id)
			{
			case 0:
			{
				char val[8];
				scanf("%s", val);
				insertInList(arr, &n, &f, index, val);
				break;
			}
			case 1:
			{
				removeFromList(arr, &n, &f, index);
				break;
			}
			default:
				break;
			}
		}

		printf("===\n");
		while (f != -1)
		{
			printf("%s\n", arr[f].val);
			f = arr[f].next;
		}
		printf("===\n");
	}

	return 0;
}