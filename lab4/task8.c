#include <stdio.h>

int max_common_factor(long int a, long int b) {
    while ((a != 0) && (b != 0)) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return a + b;
}

int main(void) {
    long long int buffer = 0;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 0, a, b;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        buffer = a * ((long long int) b / max_common_factor(a, b));
        printf("%lld\n", buffer);
    }

    return 0;
}