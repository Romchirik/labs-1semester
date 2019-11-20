#include <stdio.h>
#include <string.h>

#define N 1000000

char result[N] = {};
char number[N] = {};

int str_find_chr(char *str, char target) {
    char *pre_index = strchr(str, target);
    return pre_index - str;
}

long long int pow_int(int x, int a) {
    if (a == 0)
        return 1;
    else
        return x * pow_int(x, a - 1);
}

double translate_from_any_number_system_to_decimal(char *template, int len_template, int template_system) {
    double sum = 0;
    int point_index = str_find_chr(template, '.');

    for (int i = point_index - 1; i >= 0; i--) {
        if ((10 <= (int) template[i] - 87) && ((int) template[i] - 87 <= 16)) {
            sum += ((int) template[i] - 87) * (double) pow_int(template_system, point_index - i - 1);
        } else {
            sum += ((int) template[i] - 48) * (double) pow_int(template_system, point_index - 1 - i);
        }
    }

    for (int i = point_index + 1; i < len_template; i++) {
        if ((template[i] != '0') && (pow_int(template_system, i - point_index) != 0)){
            if ((10 <= (int) template[i] - 87) && ((int) template[i] - 87 <= 16)) {
                sum += (double) ((int) template[i] - 87) / (double) pow_int(template_system, i - point_index);
            } else {
                sum += (double) ((int) template[i] - 48) / (double) pow_int(template_system, i - point_index);
            }
        }
    }


    return sum;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int target_system, number_system;
    scanf("%d%s", &number_system, number);

    printf("%.5f", translate_from_any_number_system_to_decimal(number, strlen(number), number_system));

    return 0;
}
