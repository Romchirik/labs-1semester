#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double positive = 0, zero = 0, negative = 0;
    int n = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        if(a == 0)
            zero++;
        if(a > 0)
            positive++;
        if(a < 0)
            negative++;
    }
    printf("%.5lf %.5lf %.5lf", negative/n, zero/n, positive/n);

}
