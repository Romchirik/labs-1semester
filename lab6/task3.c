#include <stdio.h>
#include <string.h>

int result[1000] = {0};
char number[1000000] = {};

int pow_int(int x, int a) {
    if (a == 0)
        return 1;
    else
        return x * pow_int(x, a - 1);
}

int translate_from_any_number_system_to_decimal(char *template, int len_template, int template_system) {
    int sum = 0;
    for (int i = 0; i < len_template; i++) {
        if ((9 < template[i] - 87) && (template[i] - 87 < 16)) {
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

    int target_system;
    char buffer = ' ';

    scanf("%d%s", &target_system, number);

    printf("%d", translate_from_any_number_system_to_decimal(number, strlen(number), target_system));

    return 0;
}