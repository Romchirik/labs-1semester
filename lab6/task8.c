#include <stdio.h>
#include <string.h>

char im_number_one[1001] = {0};
char im_number_two[1001] = {0};
char result[1000001] = {0};

int result_lenth() {
    int counter = 0;
    int flag = 0;
    int lenth = 0;

    for (int i = 1000001; i >= 0; i--) {
        if (result[i] != 0) {
            lenth = i;
            break;
        }
    }

    if (lenth == 0) {
        return 1;
    } else {
        return lenth + 1;
    }
}

void long_addition(char *number1, char *number2, int extra_digits, int lenth2) {
    int extra = 0;
    int buffer = 0;
    int counter = 0;


    for (int i = 0; i <= lenth2; i++) {
        buffer = (int) number1[i + extra_digits] + (int) number2[i] + extra;
        extra = 0;
        if (buffer > 9) {
            extra = buffer / 10;
            buffer = buffer % 10;
        }
        result[counter + extra_digits] = buffer;
        counter++;
    }

}

void long_multiplication(char *number1, int lenth1, char *number2, int lenth2) {
    int extra = 0;
    int extra_digits = 0;
    int buffer = 0;
    int counter = 0;

    for (int i = 0; i < lenth2; i++) {
        char buffer_result[1001] = {0};
        int multiplyer = number2[i];
        for (int j = 0; j <= lenth1; j++) {
            buffer = number1[j] * multiplyer + extra;
            extra = 0;
            if (buffer > 9) {
                extra = buffer / 10;
                buffer = buffer % 10;
            }
            buffer_result[counter] = buffer;

            counter++;
        }
        long_addition(result, buffer_result, extra_digits, counter);
        buffer = 0;
        extra = 0;
        counter = 0;
        extra_digits++;

    }
}

void normalize(char *target, int len) {
    for (int i = 0; i < len; i++) {
        if ((int) target[i] == 0) {
            break;
        }
        target[i] = target[i] - 48;
    }
}

void reverse(char *target, int len) {
    len--;
    char buffer;
    for (int i = 0; i <= len / 2; i++) {
        buffer = target[i];
        target[i] = target[len - i];
        target[len - i] = buffer;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%s%s", im_number_one, im_number_two);

    int len1 = strlen(im_number_one);
    int len2 = strlen(im_number_two);
    reverse(im_number_two, len2);
    reverse(im_number_one, len1);

    normalize(im_number_one, len1);
    normalize(im_number_two, len2);

    int strcmp_res = strcmp(im_number_one, im_number_two);
    if (strcmp_res <= 0) {
        long_multiplication(im_number_two, len2, im_number_one, len1);
    } else {
        long_multiplication(im_number_one, len1, im_number_two, len2);
    }

    int len = result_lenth();
    reverse(result, len);

    for (int i = 0; i < len; i++) {
        printf("%d", (int) result[i]);
    }

}