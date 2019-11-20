#include <stdio.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    float a, b;

    scanf("%f%f", &a ,&b);

    printf("%d ", (int)floorf(a / b));
    printf("%d ", (int)ceilf(a / b));
    printf("%d ", (int)(a / b));

    if (a > 0){
        printf("%d", (int)a%(int)b);
    }
    else{
        printf("%d", (int)((ceilf(fabsf(a) / b) * b) - fabsf(a)));
    }

}