#include <stdio.h>

#define N 5000

int result[N] = {0};

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, sum = 0, sum_max = -1 * 5000 * 10000, l = 0, r = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &result[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum += result[j];
            if (sum == sum_max){
                if(j <= r)
                    r = j;
            }
            if(sum > sum_max){
                r = j;
                l = i;
                sum_max = sum;
            }
        }

        sum = 0;
    }

    printf("%d %d %d", l, r, sum_max);
    return 0;

}