#include <stdio.h>

int stat[255];

int main() {
    unsigned char ch;
    
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    while (!feof(input)) {
        fscanf(input, "%c", &ch);
        stat[ch]++;
    }

    for (int i = 13; i < 256; i++) {
        if (stat[i])
            fprintf(output, "%d : %c - %d\n", i, i, stat[i]);
    }
    
    fclose(input);
    fclose(output);

    return 0;
}