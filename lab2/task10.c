#include <stdio.h>

int pwr(int x, int a) { //возведение в степень
    if (a == 0)
        return 1;
    else
        return x * pwr(x, a - 1);
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k, lenth = 1, n = 1, counter = 0;

    scanf("%d", &k);

    while (lenth < k) {
        k -= lenth;
        n++;
        counter++;
        if (counter == 9 * pwr(10, lenth - 1)) {
            counter = 0;
            lenth++;
        }
    }
    k = lenth - k;

    n = n / pwr(10, k);
    n = n % 10;
    printf("%d", n);

}