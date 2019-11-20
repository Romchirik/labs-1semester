#include <stdio.h>
#include <string.h>

char result[3000] = {0, 0, 6, 1, 0, 0, 9, 7, 4};
char im_number_one[3000] = {0};
char a[3000] = {0};

void normalize(char *target, int len) {
    for (int i = 0; i < len; i++) {
        if ((int) target[i] == 0) {
            break;
        }
        target[i] = target[i] - 48;
    }
}

void reverse_char(char *target, int len) {
    len--;
    char buffer;
    for (int i = 0; i <= len / 2; i++) {
        buffer = target[i];
        target[i] = target[len - i];
        target[len - i] = buffer;
    }
}

void reverse_int(int *target, int len) {
    len--;
    char buffer;
    for (int i = 0; i <= len / 2; i++) {
        buffer = target[i];
        target[i] = target[len - i];
        target[len - i] = buffer;
    }
}

int result_lenth() {
    int counter = 3000 - 1;
    while ((result[counter] == 0) && counter) {
        counter--;
    }

    return counter + 1;
}


int cast_to_string(int number, int *list_to_store) {
    int counter = 0;

    while (number != 0) {
        list_to_store[counter] = number % 10;
        number = number / 10;
        counter++;
    }
    return counter;
}

int long_addition(char *number1, int number2, int extra_digits, char *result_to_store) {
    int number2_list[3000] = {0};
    int lenth = cast_to_string(number2, number2_list);
    int buffer = 0;
    int extra = 0;
    int digits_counter = 0;

    for (int i = 0; i <= lenth; i++) {

        buffer = number1[i + extra_digits] + number2_list[i] + extra;
        extra = 0;
        if (buffer > 9) {
            extra = buffer / 10;
            buffer = buffer % 10;
        }
        digits_counter++;
        result_to_store[i + extra_digits] = buffer;
    }


    return digits_counter;
}

int long_multiplication(char *number1, int lenth1, int multiplyer, char *result_middle) {
    int buffer = 0;
    int res_len = 0;
    int extra_digits = 0;
    for (int i = 0; i < 3000; i++) {
        result_middle[i] = 0;
    }
    for (int i = 0; i <= lenth1; i++) {
        buffer = multiplyer * number1[extra_digits];
        res_len = long_addition(result_middle, buffer, i, result_middle);
        extra_digits++;
    }

    if (res_len == 0) {
        res_len++;
    }
    return res_len;

}

void swap(char *string1, char *string2) {
    for (int i = 0; i < 3000; i++) {
        char buffer = string1[i];
        string1[i] = string2[i];
        string2[i] = buffer;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, result_len = 1;
    scanf("%d", &n);
    result[0] = 1;

    for (int i = 1; i <= n; i++) {
        long_multiplication(result, result_len, i, a);
        swap(result, a);
        result_len = result_lenth();
    }

    reverse_char(result, result_len);
    for (int i = 0; i < result_len; i++) {
        printf("%d", result[i]);
    }
}