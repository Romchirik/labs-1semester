#include <stdio.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x1, y1, x2, y2, x3, y3;
    double p, s;
    double l1 ,l2, l3;

    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    l1 = sqrt((double)(x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
    l2 = sqrt((double)(x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
    l3 = sqrt((double)(x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));

    p = l1 + l2 + l3;

    s = sqrt((p/2) * (p/2 - l1) * (p/2 - l2) * (p/2 - l3));

    printf("%.3lf\n%.3lf", p, s);

}