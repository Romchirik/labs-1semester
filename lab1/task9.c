#include <stdio.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x;

    scanf("%d", &x);


    if (fmod(sqrt(1 + 8*(x - 1)), 2.0) == 1)
        printf("%d", 1);
    else
        printf("%d", 0);
    return 0;
}