#include <stdio.h>

char buffer[5] = {0};

int pow(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        return a * pow(a, b - 1);
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i = 0, flag = 0, sum = 0;
    char a;

    scanf("%c", &a);

    while (a != '.') {
        if ((a - 48 >= 0) && (a - 48 <= 9)) {
            buffer[i] = a;
            i++;
            flag = 1;
        }

        scanf("%c", &a);

        if (!((a - 48 >= 0) && (a - 48 <= 9)) && (flag)) {
            for (int k = 0; k < i; k++) {
                sum += (int) (buffer[k] - 48) * pow(10, i - k - 1);
            }
            flag = 0;
            i = 0;
        }

    }
    printf("%d", sum);

    return 0;

}