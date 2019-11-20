#include <stdio.h>

#define N 1000000

int result[N] = {0};

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, left, right, mid, x, index = -1;
    scanf("%d%d", &n, &x);

    left = 0;
    right = n - 1;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &result[i]);
    }

    while (left <= right){
        mid = (left + right) / 2;
        if(result[mid] == x){
            index = mid;
        }
        if(result[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }

    printf("%d", index);

    return 0;

}