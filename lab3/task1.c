#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, counter = 0;

    scanf("%d", &n);
    int list[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(list[j] < list[i]){
                counter++;
            }
        }
        printf("%d ", counter);
        counter = 0;
    }

    return 0;

}