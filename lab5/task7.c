#include <stdio.h>
#include <string.h>

char template[7];

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i = 0, flag = 0;
    char a = '\0';

    scanf("%c", &template[0]);

    while (template[i] != ' ') {
        i++;
        scanf("%c", &template[i]);
    }
    template[i] = '\0';

    i = 0;
    if (!stricmp(template, "green")) { //blue yellow
        while (a != '\n') {
            if ((a == 'B') || (a == 'Y')){
                printf("%d ", i);
            }
            i++;
            scanf("%c", &a);
        }
    }
    if (!stricmp(template, "purple")) { //red blue
        while (a != '\n') {
            if ((a == 'R') || (a == 'B')){
                printf("%d ", i);
            }
            i++;
            scanf("%c", &a);
        }
    }
    if (!stricmp(template, "orange")) {
        while (a != '\n') {
            if ((a == 'R') || (a == 'Y')){
                printf("%d ", i);
            }
            i++;
            scanf("%c", &a);
        }
    }

    return 0;

}