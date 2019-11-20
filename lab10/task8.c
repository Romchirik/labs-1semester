#include <stdio.h>

int long_addition(int *number1, int *number2, int lenth) {
    int extra = 0;
    int buffer = 0;
    int counter = 0;

    for (int i = 0; i <= lenth; i++) {
        buffer = number1[i] + number2[i] + extra;
        extra = 0;
        if (buffer > 9) {
            extra = buffer / 10;
            buffer = buffer % 10;
        }
        number1[counter] = number2[counter];
        number2[counter] = buffer;
        counter++;
    }
    while(number2[counter] == 0){
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



int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int number_long[4000] = {1};
    int number_short[4000] = {0};

    int n, result_len = 1;
    scanf("%d", &n);

    for(int i = 1; i < n; i++){
        result_len = long_addition(number_short, number_long, result_len);
    }
    for(int i = result_len - 1; i >= 0 ; i--){
        printf("%d", number_long[i]);
    }