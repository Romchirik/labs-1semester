#include <stdio.h>

long long unsigned int stat[128] = {0};

int main() {

    char ch;
    FILE *input = fopen("input.txt", "r");


    while (fscanf(input, "%c", &ch) != EOF) {
        stat[(int) ch]++;
    }

    fclose(input);
    FILE *output = fopen("output.txt", "w");

    for (int i = 32; i < 127; i++) {
        if (stat[i] != 0) {
            fprintf(output, "%c ", (char) i);
            for (long long unsigned int j = 0; j < stat[i]; j++) {
                fprintf(output, "#");
            }
            fprintf(output, "\n");
        }
    }
    fclose(output);

}