#include <stdio.h>

char current_string[100] = {0};

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt) {
    int counter = 0;
    int a = 0;
    while (iStr[counter] != '\0') {
        if (((int) iStr[counter] >= 48) && ((int) iStr[counter] <= 57)) {
            *oDigitsCnt = *oDigitsCnt + 1;
        }
        if (((int) iStr[counter] >= 65) && ((int) iStr[counter] <= 90)) {
            *oUpperCnt = *oUpperCnt + 1;
        }
        if (((int) iStr[counter] >= 97) && ((int) iStr[counter] <= 122)) {
            *oLowerCnt = *oLowerCnt + 1;
        }
        counter++;
    }

    return counter;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    int counter = 0;

    while (gets(current_string) != NULL) {
        counter++;
        int lowercase = 0, uppercase = 0, len = 0, digits = 0;
        len = calcLetters(current_string, &lowercase, &uppercase, &digits);

        printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", counter, len,
               lowercase + uppercase, lowercase, uppercase, digits);
    }

}