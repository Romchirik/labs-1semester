#include <stdio.h>
#include <string.h>

void reverse(char *start, int len) {
    len--;
    char buffer;
    for (int i = 0; i <= len / 2; i++) {
        buffer = start[i];
        start[i] = start[len - i];
        start[len - i] = buffer;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    char string[100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", string);
        reverse(string, strlen(string));
        printf("%s\n", string);
    }

}