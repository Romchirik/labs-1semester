#include <stdio.h>
#include <string.h>

char set[1000000], buffer[1000];

int main() {


    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%s", set);


    while (scanf("%s", buffer) == 1) {
        int i = 0;
        int flag = 0;

        while (set[i] != '\0') {
            if (strchr(buffer, set[i]) != NULL) {
                flag = 1;
                break;
            }
            i++;
        }
        if (!flag) {
            printf("%s\n", buffer);
        }

        flag = 0;
    }


    return 0;

}