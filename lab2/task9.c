#include <stdio.h>
#include <math.h>

double pwr(double x, int a) { //возведение в степень
    if (a == 0)
        return 1;
    else
        return x * pwr(x, a - 1);
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double x, eps, sum = 0, delta = 0;
    int n = 0;

    scanf("%lf%lf", &x, &eps);

    do {
        delta = (pwr(-1.0, n) * pwr(x, 2 * n + 1)) / (2 * n + 1);
        sum += delta;
        n++;

    } while (fabs(delta) > eps);

    printf("%.5lf", sum);

}