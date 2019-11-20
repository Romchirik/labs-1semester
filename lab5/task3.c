#include <stdio.h>

char buffer[35];

int main(void) {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i = 0;
    scanf("%c", &buffer[0]);

    while (buffer[i] != '.') {
        i++;
        scanf("%c", &buffer[i]);
    }
    i--;
    if (buffer[i] == 'e') {
        buffer[i + 1] = 'r';
        i++;
    } else {
        if ((buffer[i - 1] == 'e') && (buffer[i] == 'r')) {
            buffer[i] = 's';
            buffer[i + 1] = 't';
            i++;
        } else {
            buffer[i + 1] = 'e';
            buffer[i + 2] = 'r';
            i += 2;
        }
    }

    for (int j = 0; j <= i; j++) {
        if(buffer[j] != '.')
            printf("%c", buffer[j]);
    }

    return 0;
}