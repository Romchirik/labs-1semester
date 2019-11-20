#include <stdio.h>

char buffer[35];

int main(void) {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i = 0;
    int sum = 0;
    scanf("%c", &buffer[0]);

    while (buffer[i] != '.') {
        i++;
        scanf("%c", &buffer[i]);
    }
    i--;

    if ((buffer[i] == '5') || (buffer[i] == '0')){
        for(int j = 0; j <= i; j ++){
            sum += (int)buffer[j] - 48;
        }
        if (sum % 3 == 0){
            printf("YES");
        } else{
            printf("NO");
        }
    } else{
        printf("NO");
    }
    return 0;
}