#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, sum = 0, delta = 0;

    scanf("%d", &n);
    int list[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    for (int i = 0; i < n; i++) {
        for(int j = i; j < n; j += i + 1){
            sum += list[j];
        }
        printf("%d\n", sum);
        sum = 0;
    }

    return 0;

}