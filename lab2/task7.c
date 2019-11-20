#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, max = -100001, min = 10001, a, min_num, max_num;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(a > max){
            max = a;
            max_num = i + 1;
        }
        if(a < min){
            min = a;
            min_num = i + 1;
        }
    }

    printf("%d %d %d %d", min, min_num, max, max_num);
