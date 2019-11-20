#include <stdio.h>

int list[100000] = {};
int a[120] = {};


int sort(int *target, int n) {

    for (int i = 1; i < n; i++) {
        int x = target[i];
        int index = i - 1;

        while ((index >= 0) && (target[index] > x)) {
            target[index + 1] = target[index];
            index --;
        }

        target[index + 1] = x;

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

    *list = sort(list, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    return 0;

}