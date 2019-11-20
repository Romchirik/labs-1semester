#include <stdio.h>

char stat[1000000];

int main() {
    int counter = 0;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    while (fgets(stat, 1000000, input) != NULL){
        counter++;
    }
    fprintf(output, "%d", counter);
    fclose(input);
    fclose(output);

    return 0;
}