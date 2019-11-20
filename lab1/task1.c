#include <stdio.h>

int main() {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);

     int k, x;

     scanf("%d%d", &k, &x);
     if (x <= k - 1){
         printf("legal");
     }
     else{
         printf("out of bounds");
     }
}