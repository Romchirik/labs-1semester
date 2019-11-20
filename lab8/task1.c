#include <stdio.h>

#define N 10000


double count_factor(int n, int k) {
    double result[N] = {0};
    int counter = 2;
    int buffer = 1;
    result[0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = j; i >= 1; i--) {
            result[i] = result[i - 1] + result[i];
        }
    }

    return result[k];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k, number_operations;
    scanf("%d", &number_operations);

    for (int i = 0; i < number_operations; i++) {
        scanf("%d%d", &n, &k);
        printf("%0.10g\n", count_factor(n, k));
    }


    for (int i = 0; i < number_operations; i++) {
        scanf("%d%d", &n, &k);
    }


}