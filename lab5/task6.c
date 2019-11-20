#include <stdio.h>

char template[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                     't', 'u', 'v',
                     'w', 'x', 'y', 'z'};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i = 0, flag = 0;
    char a;
    scanf("%c", &a);

    while ((a != '\n') && (i != 27)) {

        while ((a != ' ') && (a != '\n')) {
            if (a == template[i]) {
                flag = 1;
            }
            scanf("%c", &a);

        }
        if (flag == 0) {
            if (i % 2 == 0) {
                printf("PLAYER 2");
                return 0;
            } else {
                printf("PLAYER 1");
                return 0;
            }
        }

        flag = 0;
        scanf("%c", &a);
        i++;
    }

    printf("NO WINNER");

    return 0;