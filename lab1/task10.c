#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, m, s, delta;
    int total_sec;

    scanf("%d%d%d%d", &h, &m, &s, &delta);

    total_sec = h * 3600 + m * 60 + s + delta;
    h = total_sec / 3600;
    h = h % 24;
    total_sec = total_sec % 3600;
    m =  total_sec / 60;
    total_sec = total_sec % 60;
    s = total_sec;
    printf("%d %d %d", h, m, s);
}