#include <stdio.h>

int result[1000] = {0};

int decimal_to_any_number_system(int target, int b) {
    int counter = 0;

    do {
        result[counter] = target % b;
        target = target / b;
        counter++;
    }  while (target > 0);
    return counter;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int b;
    long int target_number;

    scanf("%d%ld", &b, &target_number);

    int i = decimal_to_any_number_system(target_number, b) - 1;
    for (int a = i; a >= 0; a--) {
        if (result[a] > 9) {
            printf("%c", (char) result[a] + 87);
        } else {
            printf("%d", result[a]);
        }
    }

    return 0;
}