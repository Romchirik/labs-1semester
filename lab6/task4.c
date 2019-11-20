#include <stdio.h>
#include <string.h>

#define N 1000000

char result[N] = {};
char number[N] = {};


int pow_int(int x, int a) {
    if (a == 0)
        return 1;
    else
        return x * pow_int(x, a - 1);
}


int translate_from_decimal_to_any_number_system(int target, int b) {
    int counter = 0;
    do {
        if (target % b > 9) {
            result[N - counter] = (target % b + 87);
        } else {
            result[N - counter] = (target % b + 48);
        }

        target = target / b;
        counter++;
    } while (target > 0);
    return counter;
}

int translate_from_any_number_system_to_decimal(char *template, int len_template, int template_system) {
    int sum = 0;
    for (int i = 0; i < len_template; i++) {
        if ((9 < (int)template[i] - 87) && ((int)template[i] - 87 < 36)) {
            sum += ((int) template[i] - 87) * pow_int(template_system, len_template - i - 1);
        } else {
            if ((int) template[i] - 48 != 0)
                sum += ((int) template[i] - 48) * pow_int(template_system, len_template - i - 1);
        }
    }
    return sum;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int target_system, number_system;

    scanf("%d%d%s", &number_system, &target_system, number);

    int a = translate_from_decimal_to_any_number_system(
            translate_from_any_number_system_to_decimal(number, strlen(number), number_system),
            target_system
    );

    for (int i = 0; i < a; i++) {
        printf("%c", result[N - a + i + 1]);
    }

    return 0;
}