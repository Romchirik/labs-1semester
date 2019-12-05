#include <stdio.h>

typedef struct List {
	int data;
	int next;
	int prev;
} list;

list A[100001];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, T;
	scanf("%d\n", &T);
	for (t = 0; t < T; t++) {
		int n, l, f, q;
		scanf("%d %d %d %d", &n, &f, &l, &q);
		A[0].next = f + 1;
		A[0].prev = l + 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &A[i].data, &A[i].next, &A[i].prev);
			A[i].next++;
			A[i].prev++;
		}
		for (int i = 0; i < q; i++) {
			int operation, index;
			scanf("%d%d", &operation, &index);
			switch (operation) {
			case 1: {
						int val;
						scanf("%d", &val);
						n++;
						int tmp = A[index+1].next;
						A[n].data = val;
						A[tmp].prev = n;
						A[n].next = A[index+1].next;
						A[index+1].next = n;
						A[n].prev = index + 1;
						printf("%d\n", n - 1);
						break;
			}
			case -1: {
						 int val;
						 scanf("%d", &val);
						 n++;
						 int tmp = A[index+1].prev;
						 A[n].data = val;
						 A[tmp].next = n;
						 A[n].prev = A[index+1].prev;
						 A[n].next = index + 1;
						 A[index+1].prev = n;
						 printf("%d\n", n - 1);
						 break;
			}
			case 0: {
						int d = A[index + 1].data;
						int tmp_prev = A[index+1].prev;
						int tmp_next = A[index+1].next;
						A[tmp_prev].next = A[index+1].next;
						A[tmp_next].prev = A[index+1].prev;
						printf("%d\n", d);
						break;
			}

			default:
				break;
			}
		}
		printf("===\n");
		for (int j = A[0].next; j != 0; j = A[j].next) {
			printf("%d\n", A[j].data);
		}
		printf("===\n");
	}

	return 0;
}
