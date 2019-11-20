#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, sum = 0, delta = 0;

    scanf("%d", &n);
    int a;
    int result[10001] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        result[a]++;
    }

    for (int i = 0; i < 10001; i++) {
        if(result[i] != 0){
            printf("%d: %d\n", i, result[i]);
        }
    }
    return 0;

}