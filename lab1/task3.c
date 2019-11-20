include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x1, x2, x3;

    scanf("%d%d%d", &x1, &x2, &x3);

    if (x1<=x2 && x1<=x3){
        printf("%d", x1);
        return 0;
    }
    else{
        if (x2<=x3){
            printf("%d", x2);
            return 0;
        }
        else{
            printf("%d", x3);
            return 0;
        }
    }

}