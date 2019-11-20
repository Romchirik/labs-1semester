#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unsigned int number, counter = 0, max = 0;

    scanf("%d", &number);

    while (number != 0){
        if(number & 1){
            counter ++;
        } else{
            counter = 0;
        }
        if(counter > max){
            max = counter;
        }
        number >>= 1;
    }

    printf("%d", max);

    return 0;
}