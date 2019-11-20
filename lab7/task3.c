#include <stdio.h>

int reverse_bit(unsigned int value, int value_size) {
    int buffer = 0;

    for (int i = 0; i < value_size; i++) {
        buffer = (buffer << 1) | (value & 1);
        value >>= 1;
    }

    return buffer;

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int number;

    scanf("%u", &number);
    number = reverse_bit(number, 8 * sizeof(number));

    int output = number;

    for (int i = 0; i < 32; i++) {
        printf("%d", output & 1);
        output >>= 1;
    }
    printf("\n%d\n", number);

    number = reverse_bit(number, 8* sizeof(number));

    output = number;

    for (int i = 0; i < 32; i++) {
        printf("%d", output & 1);
        output >>= 1;
    }
    return 0;

}