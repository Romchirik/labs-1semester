#include <stdio.h>

int power_recoery(int broken_result) {
    int power_counter = 0;
    while (!(broken_result & 1)) {
        power_counter++;
        broken_result >>= 1;
    }
    return 1 << power_counter;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; //number of inputs
    int broken_result;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &broken_result);
        printf("%d\n", power_recoery(broken_result));
    }

}