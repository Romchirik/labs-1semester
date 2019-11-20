#include <stdio.h>

#define N 312500
#define ARRAY_EL_SIZE 32

typedef unsigned int bitword;


bitword bit_array[N];

void bitsetZero(bitword *arr, int num) {
    for (int i = 0; i < (num + ARRAY_EL_SIZE - 1) / ARRAY_EL_SIZE; i++) {
        arr[i] = 0;
    }
}

int bitsetGet(const bitword *arr, int idx) {
    return (arr[idx / ARRAY_EL_SIZE] >> (ARRAY_EL_SIZE - 1 - (idx % ARRAY_EL_SIZE))) & 1;
}

void bitsetSet(bitword *arr, int idx, int newval) {
    if (newval) {
        arr[idx / ARRAY_EL_SIZE] = arr[idx / ARRAY_EL_SIZE] | (1 << (ARRAY_EL_SIZE - 1 - idx));
    } else {
        arr[idx / ARRAY_EL_SIZE] = arr[idx / ARRAY_EL_SIZE] & ~(1 << (ARRAY_EL_SIZE - 1 - idx));
    }
}

int bitsetAny(const bitword *arr, int left, int right) {
    unsigned int mask_left = (unsigned int) (0 - 1) >> (left % ARRAY_EL_SIZE);
    unsigned int mask_right = (unsigned int) (0 - 2) << (ARRAY_EL_SIZE - 1 - (right % ARRAY_EL_SIZE));
    unsigned int result_for_comparsion = 0;


    if (left / ARRAY_EL_SIZE == right / ARRAY_EL_SIZE) {
        result_for_comparsion = arr[left / ARRAY_EL_SIZE] & mask_left & mask_right;
    } else {
        result_for_comparsion = mask_left & arr[left / ARRAY_EL_SIZE];
        result_for_comparsion = result_for_comparsion | (mask_right & arr[right / ARRAY_EL_SIZE]);
        for (int i = (left / ARRAY_EL_SIZE) + 1; i <= (right / ARRAY_EL_SIZE) - 1; i++) {
            result_for_comparsion = result_for_comparsion | arr[i];
        }
    }
    
    if (result_for_comparsion) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int num_operations, operation_name, bit_array_lenth = 0;
    int counter = 0;
    scanf("%d", &num_operations);

    for (int i = 0; i < num_operations; i++) {
        scanf("%d", &operation_name);
        if (operation_name == 0) {
            scanf("%d", &bit_array_lenth);
            bitsetZero(bit_array, bit_array_lenth);
        }
        if (operation_name == 1) {
            int bit_index;
            scanf("%d", &bit_index);
            printf("%d\n", bitsetGet(bit_array, bit_index));
            counter++;
        }
        if (operation_name == 2) {
            int idx, newval;
            scanf("%d%d", &idx, &newval);
            bitsetSet(bit_array, idx, newval);
        }
        if (operation_name == 3) {
            int left, right;
            scanf("%d%d", &left, &right);
            counter++;
            if (bitsetAny(bit_array, left, right)) {
                printf("some\n");
            } else {
                printf("none\n");
            }
        }
    }

}