#include <stdio.h>

char set[26], template[26] = {0};

void check_set(char *target, int n) {
    int k = 0;

    while (target[k] != '\0') {
        int b = (int) target[k] - 65;
        template[b] += n;
        k++;

    }
}

int main() {


    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%s", set);
    check_set(set, 1);

    scanf("%s", set);
    check_set(set, 2);
    int flag = 0;
    for (int i = 0; i < 26; i++) {
        if (template[i] == 1) {
            flag = 1;
            printf("%c", template[i] + 64 + i);
        }
    }
    if (!flag){
        printf("Empty Set");
    }
    return 0;

}