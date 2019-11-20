#include <stdio.h>

int max_common_factor(int a, int b) {
    while ((a != 0) && (b != 0)) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return a + b;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;

    scanf("%d%d", &a, &b);

    printf("%d", max_common_factor(a, b));

    return 0;

}