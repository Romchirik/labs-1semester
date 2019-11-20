#include <stdio.h>

int list[1000] = {};

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j ++){
            if (list[j] > i + 1)
                sum++;
            if (list[j] == i + 1)
                break;
        }
        printf("%d ", sum);
    }

    return 0;
}