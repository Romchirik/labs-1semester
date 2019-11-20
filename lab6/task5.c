//оч кривой, но рабочий код

#include <stdio.h>
#include <string.h>
#include <math.h>

char float_part[500] = {0};

long long int pow_int(int x, int a) {
    if (a == 0)
        return 1;
    else
        return x * pow_int(x, a - 1);
}

void translate_float_part(double template, int target_system, int max_digits) {
    double garbage = 0;
    for (int i = 0; i <= max_digits; i++) {
        if (template == 0) {
            float_part[0] = '0';
            break;
        }
        template = template * (double) target_system;

        if (ceil(template + 0.00000001) != ceil(template)) {
            template = ceil(template);
        }

        if ((int) template > 9) {
            float_part[i] = 87 + (int) template;
        } else {
            float_part[i] = 48 + (int) template;
        }
        template = modf(template, &garbage);

        if (template < 0.00001) {
            break;
        }
        


    }

    float_part[max_digits] = '\0';
    for (int i = max_digits; i > 0; i--) {
        if ((float_part[i] == '0') || (float_part[i] == '\0'))
            float_part[i] = '\0';
        else
            break;
    }

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int target_system, max_digits;
    double number = 0;
    scanf("%d%d", &target_system, &max_digits);

    scanf("%lf", &number);

    translate_float_part(number, target_system, max_digits);

    printf("0.%s", float_part);


}