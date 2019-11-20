#include <stdio.h>

#define N 1000000

int mass[N];

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

void swap(int *a, int *b) {
    int buffer = *a;
    *a = *b;
    *b = buffer;
}

void insert_sort(int *target, int start_index, int step, int len) {
    len = len - 1;
    int i = start_index + step;
    while (i <= len) {
        int x = target[i];
        int j = i - step;
        while ((j >= start_index) && (target[j] > x)) {
            target[j + step] = target[j];
            j -= step;
        }
        target[j + step] = x;
        i += step;
    }
}

void shell_sort(int *target, int len) {
    int step = 1;
    while (step < len / 3) {
        step = 3 * step + 1;
    }

    while (step > 0) {
        for (int i = 0; i < step; i++) {
            insert_sort(target, i, step, len);
        }
        step = (step - 1) / 3;
    }
}

int main(void) {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int lenth = scanf_mass_int(mass);
    shell_sort(mass, lenth);
    printf_mass_int(mass, lenth);

}