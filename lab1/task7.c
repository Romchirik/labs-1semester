#include <stdio.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if ((a == 0) & (b == 0)){
        if (c == 0) {
            printf("MANY");
            return 0;
        } else{
            printf("ERROR");
            return 0;
        }
    }

    if (a == 0){
        printf("%d\n%.5lf", 1, (double)(-c) / b);
        return 0;
    }

    double d, x1, x2;

    d = b * b - 4 * c * a;
    
    if (d == 0){
        printf("%d\n%.5lf", 1, (double)-b/2*a);
        return 0;
    }
    if (d < 0) {
        printf("NO");
        return 0;
    }

    x1 = (-1 * b + sqrt(d)) / (2 * a);
    x2 = (-1 * b - sqrt(d)) / (2 * a);

    if (x1 > x2)
        printf("%d\n%.5lf %.5lf", 2, x2, x1);
    else
        printf("%d\n%.5lf %.5lf", 2, x1, x2);
    return 0;
}