#include <stdio.h>

int list[1000] = {0};
int reshape[1000] = {};

int check_reshape(int *target, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (target[i] > n - 1 - i) {
            return 1;
        }
    }
    return 0;
}

int find_index(int free, int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        if (free == 0) {
            while (list[i] != 0) {
                i++;
            }
            break;
        } else {
            if (list[i] == 0)
                free--;
        }

    }
    return i;
}

int assemble(int *template, int n) {
    for (int i = 0; i < n; i++) {
        list[find_index(template[i], n)] = i + 1;
    }
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &reshape[i]);
    }
    if (check_reshape(reshape, n)) {
        printf("NO");
        return 0;
    }
    assemble(reshape, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    return 0;
}