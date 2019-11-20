#include <stdio.h>

#define N 1000000

long long int mass[N];

void swap(long long int *a, long long int *b) {
    long long int buffer = *a;
    *a = *b;
    *b = buffer;
}


void qsort(long long int *target, int left, int right) {
    int low = left, high = right;
    long long int pivot = target[(left + right) / 2];
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
    if (low < right) {
        qsort(target, low, right);
    }
    if (high > left) {
        qsort(target, left, high);
    }
}


int scanf_mass_int(long long int *result_storage) {
    long long int n;
    scanf("%lli", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lli", &result_storage[i]);
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
    freopen("output.txt", "w", stdout);

    long long int sum = 0;
    int length = scanf_mass_int(mass);
    qsort(mass, 0, length - 1);

    for (int i = 0; i < length; i++) {
        sum += mass[i] * (length - 1 - i);
    }


    printf("%lld", sum);
    return 0;
}