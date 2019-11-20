#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, sum = 0;

    scanf("%d", &n);
    int a;
    int result_positive[1001] = {0};
    int result_negative[1001] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);

        if (a >= 0)
            result_positive[a]++;
        else
            result_negative[(-1) * a]++;
    }

    for (int i = 0; i < 1001; i++) {
        if (result_positive[i] != 0)
            sum++;
        if (result_negative[i] != 0)
            sum++;
    }

    printf("%d", sum);
    return 0;

}