#include <stdio.h>
#include <math.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, result;
    double a, delta = 1;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a);
        a = fabs(a);
        if (a - floor(a) < delta) {
            result = i;
            delta = a - floor(a);
        }
        if (ceilf(a) - a < delta) {
            result = i;
            delta = ceilf(a) - a;
        }
    }

    printf("%d", result);
}