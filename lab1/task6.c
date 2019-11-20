#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    int x , y, z;

    scanf("%d%d%d", &x, &y, &z);

    if (x <= 0){
        printf("%d", -1);
        return 0;
    }
    else{
        if (y <= 0){
            printf("%d", -2);
            return 0;
        } else{
            if (z <= 0){
                printf("%d", -3);
                return 0;
            }
        }
    }

    printf("%d", x * y * 2 + y * z * 2 + x * z * 2);

}