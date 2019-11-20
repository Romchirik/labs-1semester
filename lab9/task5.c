#include <stdio.h>

char text[1000][1002];

int main() {

    unsigned int counter = 0;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    while (!feof(input)) {
        fgets(text[counter], 1002, input);
        counter++;
    }

    for (int i = counter - 2; i >= 0; i--) {
        fprintf(output, "%s", text[i]);
    }

    fclose(input);
    fclose(output);
    return 0;
}