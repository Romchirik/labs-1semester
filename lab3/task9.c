#include <stdio.h>
#include <math.h>

#define N 1000000

double result[N] = {0};

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, left, right, mid = 0, lmid = 1, x;
    scanf("%d%d", &n, &x);

    left = 0;
    right = n - 1;

    for (int i = 0; i < n; ++i) {
        scanf("%lf", &result[i]);
    }

    while (lmid != mid) {
        lmid = mid;
        mid = (left + right) / 2;
        if (result[mid] > x) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if ((result[mid] > x) && (mid != 0))
        mid--;

    
    if (fabs(result[mid] - x) <= fabs(result[mid + 1] - x))
        printf("%d", mid);
    else
        printf("%d", mid + 1);

    return 0;

}