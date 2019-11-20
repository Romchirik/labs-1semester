#include <stdio.h>

#define N 312500
#define ARRAY_EL_SIZE 32

typedef unsigned int bitword;


bitword bit_array[N];

void bitsetSet(bitword *arr, int idx, int newval) {
    if (newval) {
        arr[idx / ARRAY_EL_SIZE] = arr[idx / ARRAY_EL_SIZE] | (1 << (ARRAY_EL_SIZE - 1 - idx));
    } else {
        arr[idx / ARRAY_EL_SIZE] = arr[idx / ARRAY_EL_SIZE] & ~(1 << (ARRAY_EL_SIZE - 1 - idx));
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int num_operations, num_numbers, index;
    int newval;
    scanf("%d%d", &num_numbers, &num_operations);

    for(int i = 0; i < num_numbers; i++){
        scanf("%d", &bit_array[i]);
    }

    for (int i = 0; i < num_operations; i++) {
        scanf("%d%d", &newval, &index);
        bitsetSet(bit_array, index, newval);

    }

    for(int i = 0; i < num_numbers; i ++){
        printf("%d ", (int)bit_array[i]);
    }

}