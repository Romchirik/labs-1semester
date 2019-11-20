#include <stdio.h>

#define N 1000000

int mass[N];

void swap(int *a, int *b) {
    int buffer = *a;
    *a = *b;
    *b = buffer;
}


void qsort(int *target, int left, int right) {
    int low = left, high = right;
    int pivot = target[(left + right) / 2];
    while (left <= right) {
        while (target[left] < pivot) {
            left++;
        }
        while (target[right] > pivot) {
            right--;
        }
        if (left <= right) {
            swap(&target[left++], &target[right--]);
        }
    }
    if (low < right){
        qsort(target, low, right);
    }
    if(high > left){
        qsort(target, left, high);
    }
}

int scanf_mass_int(int *result_storage) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &result_storage[i]);
    }
    return n;
}

void printf_mass_int(int *mass_to_print, int lenth) {
    for (int i = 0; i < lenth; i++) {
        printf("%d ", mass_to_print[i]);
    }
}

int main(void) {

    freopen("input.txt", "r", stdin);
    FILE *output = fopen("output.txt", "w");

    int counter = 0;
    int lenth = scanf_mass_int(mass);
    qsort(mass, 0, lenth - 1);
    fprintf(output, "      \n");

    if(lenth != 0){
        fprintf(output, "%d\n", mass[0]);
        counter++;
        for(int i = 1; i < lenth; i++){
            if(mass[i - 1] != mass[i]){
                counter++;
                fprintf(output, "%d\n", mass[i]);

            }
        }
        fseek(output, 0, SEEK_SET);
        fprintf(output, "%d", counter);
    } else{

        printf("0");
    }
    return 0;
}