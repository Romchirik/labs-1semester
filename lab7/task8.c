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

void bitsetSetSeg(bitword *arr, int left, int right, int newval) {
    if (newval == 1) {
        unsigned int mask_left = (unsigned int) (0 - 1) >> (left % ARRAY_EL_SIZE);
        unsigned int mask_right = (unsigned int) (0 - 2) << (ARRAY_EL_SIZE - 1 - (right % ARRAY_EL_SIZE));

        if (left / ARRAY_EL_SIZE == right / ARRAY_EL_SIZE) {
            arr[left / ARRAY_EL_SIZE] = arr[left / ARRAY_EL_SIZE] | (mask_left & mask_right);
        } else {
            arr[left / ARRAY_EL_SIZE] = arr[left / ARRAY_EL_SIZE] | mask_left;
            arr[right / ARRAY_EL_SIZE] = arr[right / ARRAY_EL_SIZE] | mask_right;
            for (int i = (left / ARRAY_EL_SIZE) + 1; i <= (right / ARRAY_EL_SIZE) - 1; i++) {
                arr[i] = arr[i] | 0xffffffffffffffff;
            }
        }
    } else {
        unsigned int mask_left = ~((unsigned int) (0 - 1) >> (left % ARRAY_EL_SIZE));
        unsigned int mask_right = ~((unsigned int) (0 - 2) << (ARRAY_EL_SIZE - 1 - (right % ARRAY_EL_SIZE)));

        if (left / ARRAY_EL_SIZE == right / ARRAY_EL_SIZE) {
            arr[left / ARRAY_EL_SIZE] = arr[left / ARRAY_EL_SIZE] & (mask_left | mask_right);
        } else {
            arr[left / ARRAY_EL_SIZE] = arr[left / ARRAY_EL_SIZE] & mask_left;
            arr[right / ARRAY_EL_SIZE] = arr[right / ARRAY_EL_SIZE] & mask_right;
            for (int i = (left / ARRAY_EL_SIZE) + 1; i <= (right / ARRAY_EL_SIZE) - 1; i++) {
                arr[i] = arr[i] & 0x0000000000000000;
            }
        }
    }

}

int count_1bits(unsigned int n) {
    n = ((n >> 1) & 0x55555555) + (n & 0x55555555);
    n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
    n = ((n >> 4) & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n = ((n >> 8) & 0x00FF00FF) + (n & 0x00FF00FF);
    n = ((n >> 16) & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}

int bitsetCount(const bitword *arr, int left, int right) {
    unsigned int mask_left = (unsigned int) (0 - 1) >> (left % ARRAY_EL_SIZE);
    unsigned int mask_right = (unsigned int) (0 - 2) << (ARRAY_EL_SIZE - 1 - (right % ARRAY_EL_SIZE));
    int counter = 0;

    if (left / ARRAY_EL_SIZE == right / ARRAY_EL_SIZE) {
        counter += count_1bits(arr[left / ARRAY_EL_SIZE] & mask_left & mask_right);
    } else {
        counter += count_1bits(arr[left / ARRAY_EL_SIZE] & mask_left);
        counter += count_1bits(arr[right / ARRAY_EL_SIZE] & mask_right);
        for (int i = (left / ARRAY_EL_SIZE) + 1; i <= (right / ARRAY_EL_SIZE) - 1; i++) {
            counter += count_1bits(arr[i]);
        }
    }
    return counter;
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
            int left, right, newval;
            scanf("%d%d%d\n", &left, &right, &newval);
            bitsetSetSeg(bit_array, left, right, newval);
        }
        if (operation_name == 4) {
            int left, right;
            scanf("%d%d", &left, &right);
            printf("%d\n", bitsetCount(bit_array, left, right));
            counter++;
        }
    }

}