#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long int n1, n2 = 0;
    scanf("%ld", &n1);

    while(n1 > 0){
        n2 *= 10;
        n2 += n1 % 10;
        n1 /= 10;
    }
    printf("%ld", n2);
    
}
