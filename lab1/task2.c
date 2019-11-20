#include <stdio.h>

int main() {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);

     float x, y, z;

     scanf("%f%f%f", &x, &y, &z);
     printf("%f", x*y*z);
}