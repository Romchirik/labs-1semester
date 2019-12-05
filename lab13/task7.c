#include <stdio.h>
#include <stdlib.h>

#define N 1000001
typedef struct Node_s {
    int length;
    char **data;
} Node;

Node data[N];

int main(void) {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int key;
        char *buffer = malloc(8 * sizeof(char));
        scanf("%d %s", &key, buffer);

        if (data[key].length == 0) {
            data[key].data = malloc(sizeof(char *));
            data[key].data[0] = buffer;
            data[key].length = 1;
            continue;
        }

        data[key].data = realloc(data[key].data, (data[key].length + 1) * sizeof(char *));
        data[key].data[data[key].length] = buffer;
        data[key].length++;

    }

    for (int i = 0; i < N; i++) {
        if (data[i].length != 0) {
            for (int j = 0; j < data[i].length; j++) {
                printf("%d %s\n", i, data[i].data[j]);
            }
        }
    }
}