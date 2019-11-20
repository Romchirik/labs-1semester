//сдавать только в крайнем случае (написано не по теме, вероятнее всего этот код при проверке не примут)

#include <stdio.h>
#include <string.h>

#define N 100000

char data[N] = {};

int pow_int(int x, int a) {
    if (a == 0)
        return 1;
    else
        return x * pow_int(x, a - 1);
}

int translate_from_any_number_system_to_decimal(char *template, int len_template, int template_system) {
    int sum = 0;
    for (int i = len_template - 1; i >= 0; i--) {
        if ((9 < template[i] - 87) && (template[i] - 87 < 16)) {
            sum += ((int) template[i] - 87) * pow_int(template_system, len_template - 1 - i);
        } else {
            if ((int) template[i] - 48 != 0)
                sum += ((int) template[i] - 48) * pow_int(template_system, len_template - 1 - i);
        }
    }
    return sum;
}


int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a;
    scanf("%d%s", &a, data);
    int lenth = strlen(data);

    for (int i = 0; i < lenth; i += 8) {
        char buffer[9] = {0};
        for (int j = 0; j < 8; j++) {

            buffer[j] = data[i + j];

            if (data[i + j] == '\0')
                break;
        }
        printf("%d ", translate_from_any_number_system_to_decimal(strrev(buffer), strlen(buffer), 2));
    }


    return 0;
}
