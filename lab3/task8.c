#include <stdio.h>

#define N 100000

int result[N] = {0};

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k, buffer;
    scanf("%d%d", &n, &k);
    k = k % n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &result[i]);
    }

    if (k == 0) {
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        return 0;
    }

    for (int i = 0; i < n / 2; i++) {
        buffer = result[i];
        result[i] = result[n - 1 - i];
        result[n - 1 - i] = buffer;
    }

    for (int i = 0; i < k / 2; i++) {
        buffer = result[i];
        result[i] = result[k - 1 - i];
        result[k - 1 - i] = buffer;
    }

    for (int i = 0; i < (n - k) / 2; i++) {
        buffer = result[k + i];
        result[k + i] = result[n - i - 1];
        result[n - 1 - i] = buffer;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;

}