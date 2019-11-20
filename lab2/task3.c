#include <stdio.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, n;
    scanf("%d", &a);

    if (a == 1){
        printf("NO");
        return 0;
    }

    n = (int)sqrt(a) + 1;

    for(int i = 2; i < n; i++){
        if(a % i == 0){
            printf("NO");
            return 0;
        }
    }
    printf("YES");

}