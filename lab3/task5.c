#include <stdio.h>

int result[1000000] = {0};

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < 1000001; i++) {
        result[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i){
            result[j] = 0;
        }

    }

    for (int i = 2; i <= n; i++) {
        if (result[i] != 0)
            printf("%d ", result[i]);
    }
    return 0;

}