#include <stdio.h>

int list[100000] = {};

int assemble(int *target, int n) {
    int left = 0, right = n - 1;
    int flag = 1;

    while ((left < right) && (flag)) {
        flag = 0;

        for (int i = left; i < right; i++) {
            if (target[i] > target[i + 1]) {
                int buffer = target[i];
                target[i] = target[i + 1];
                target[i + 1] = buffer;
                flag = 1;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (target[i-1] > target[i]) {
                int buffer = target[i];
                target[i] = target[i - 1];
                target[i - 1] = buffer;
                flag = 1;
            }
        }
        left++;
    }
    return *target;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    *list = assemble(list, n);

    for (int i = 0; i < n; i ++){
        printf("%d ", list[i]);
    }

    return 0;
}