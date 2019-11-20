//thanks https://vk.com/bby_ch

#include <stdio.h>
#include <math.h>

#define N 200

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    double a[N][N + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    int k = 0, index;
    double max, x[N];
    while (k < n) {
        max = (a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++) {
            if ((a[i][k]) > max) {
                max = (a[i][k]);
                index = i;
            }
        }
        for (int j = 0; j < n + 1; j++) {
            double temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }
        for (int i = k; i < n; i++) {
            double temp = a[i][k];
            if (temp == 0) continue;
            for (int j = 0; j < n + 1; j++)
                a[i][j] = a[i][j] / temp;
            if (i == k) continue;
            for (int j = 0; j < n + 1; j++)
                a[i][j] = a[i][j] - a[k][j];
        }
        k++;
    }
    for (k = n - 1; k >= 0; k--) {
        x[k] = a[k][n];
        for (int i = 0; i < k; i++)
            a[i][n] = a[i][n] - a[i][k] * x[k];
    }

    for (int i = 0; i < n; i++)
        printf("%.10lf\n", x[i]);
    return 0;
}