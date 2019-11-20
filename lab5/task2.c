#include <stdio.h>


int main(void) {
    char a;
    int flag = 0;
    int i = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    scanf("%c", &a);

    while (a != '.') {
        if ((i == 1) && (a == 'A'))
            flag = 1;
        scanf("%c", &a);
        i++;
    }
    if ((flag) && (i == 3)) {
        printf("FITS");
    } else {
        printf("DOES NOT FIT");
    }
    return 0;
}