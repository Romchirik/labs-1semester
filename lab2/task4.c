#include <stdio.h>
#include <math.h>

_Bool is_simple(int x) {
    int b = (int)sqrt(x) + 1;
    for(int i = 2; i <= b; i ++){
        if((x % i == 0) & (x!=2))
            return 0;
    }
    return 1;
}


int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for(int i = 2; i <= n; i++){
        if(is_simple(i) == 1){
            printf("%d ", i);
        }
    }
    return 0;
}