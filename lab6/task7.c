#include <stdio.h>
#include <string.h>

#include <math.h>

char number[900] = {0};
char float_part[900] = {0};
int int_part[900] = {0};

long long int pow_int(int x, int a) {
    if (a == 0)
        return 1;
    else
        return x * pow_int(x, a - 1);
}

int decimal_to_any_number_system(int target, int b) {
    int counter = 0;

    do {
        int_part[counter] = target % b;
        target = target / b;
        counter++;
    }  while (target > 0);

    return counter;
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
    for (int i = max_digits; i >= 0; i--) {
        if ((float_part[i] == '0') || (float_part[i] == '\0'))
            float_part[i] = '\0';
        else
            break;
    }

}

int str_find_chr(char *str, char target) {
    char *pre_index = strchr(str, target);
    if (pre_index == NULL){
        return -1;
    } else{
        return pre_index - str;
    }
}


double translate_from_any_number_system_to_decimal(char *template, int len_template, int template_system) {
    double sum = 0;
    int point_index = str_find_chr(template, '.');

    if (point_index == -1){
        point_index = len_template;
    }

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

int check_input(char *template, int len, int start_system){
    int counter = 0;

    for(int i = 0; i < len; i ++){
        if (template[i] != '.'){
            if(((int) template[i] > 47) && ((int) template[i] < 58)){
                if ((int) template[i] - 48 >= start_system){
                    return 1;
                }

            }
            if(((int) template[i] > 96) && ((int) template[i] < 103)){
                if ((int) template[i] - 87 >= start_system){
                    return 1;
                }

            }
        } else{
            counter++;
        }
    }
    if(counter > 1){
        return 1;
    } else{
        return 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int target_system, max_digits, start_system;

    scanf("%d%d%d",&start_system, &target_system, &max_digits);
    scanf("%s", number);

    if (check_input(number, strlen(number), start_system)){
        printf("NO");
        return 0;
    }
    double middle_value = translate_from_any_number_system_to_decimal(number, strlen(number), start_system);

    translate_float_part(middle_value - (int) middle_value, target_system, max_digits);
    int len = decimal_to_any_number_system((int) middle_value, target_system) - 1;
    for (int a = len; a >= 0; a--) {
        if (int_part[a] > 9) {
            printf("%c", (char) int_part[a] + 87);
        } else {
            printf("%d", int_part[a]);
        }
    }

    if(!(float_part[0] == '\0'))
        printf(".%s", float_part);

    return 0;
}