#include <stdio.h>
#include <string.h>

int a[31] = {0};

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    char ch[255];

    while (fscanf(input, "%s", ch) == 1) {
        int len = strlen(ch);
        a[len]++;
    }

    for (int i = 1; i < 32; i++) {
        if (a[i] > 0)
            fprintf(output, "%d - %d\n", i, a[i]);
    }
    fclose(input);
    fclose(output);
    return 0;
}