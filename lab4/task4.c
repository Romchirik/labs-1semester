#include <stdio.h>

int list[100000] = {};

int sort(int *target, int n) {
    for (int i = 0; i < n; i++) {

        int min = target[i];
        int index = i;
        int buffer;

        for (int j = i; j < n; j++) {
            if(target[j] < min){
                index = j;
                min = target[j];
            }
        }

        buffer = target[i];
        target[i] = target[index];
        target[index] = buffer;

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
    scanf("%d", &n);

    *list = sort(list, n);

    for (int i = 0; i < n; i ++){
        printf("%d ", list[i]);
    }
    return 0;
}