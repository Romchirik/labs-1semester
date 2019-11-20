#include <stdio.h>

int main(void) {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char c;
    int counter = 0, flag = 0;
    scanf("%c", &c);

    while (c != '\n') {

        if ((flag == 0) && (c != '.')) {
            flag = 1;
            counter++;
        }
        if ((flag == 1) && (c == '.')) {
            flag = 0;
        }
        scanf("%c", &c);
    }

    printf("%d", counter);

    return 0;
}