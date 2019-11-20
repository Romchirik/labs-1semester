#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, p, k, l, a, b;

    scanf("%d%d%d%d%d", &n, &m, &p, &k, &l);

    a = m / (((p - 1) * l) + k - 1);

    if (n % (a * l) == 0)
        b = n / (a * l);
    else
        b = n / (a * l) + 1;

    printf("%d ", b);

    if (n % a == 0)
        printf("%d", (n - (b - 1)*a*l) / a);
    else
        printf("%d", ((n - (b - 1)*a*l) / a) + 1);

}