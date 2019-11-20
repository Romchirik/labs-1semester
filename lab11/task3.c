//кривая реализация (сортирует с 1 элемента, а не с 0), переделать под 0 элемент так и не смог

#include <stdio.h>

#define N 1000001

int mass[N];

int scanf_mass_int(int *result_storage) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &result_storage[i]);
    }
    return n;
}

void printf_mass_int(int *mass_to_print, int lenth) {
    for (int i = 1; i <= lenth; i++) {
        printf("%d ", mass_to_print[i]);
    }
}

void swap(int *a, int *b) {
    int buffer = *a;
    *a = *b;
    *b = buffer;
}

void shifting(int *target, int el_index_to_shift, int last_index) {
    int index;
    while (2 * el_index_to_shift <= last_index) {
        index = 2 * el_index_to_shift;
        if (index + 1 <= last_index && target[index] < target[index + 1])
            index++;
        if (target[el_index_to_shift] < target[index]) {
            swap(&target[el_index_to_shift], &target[index]);
            el_index_to_shift = index;
        } else
            break;
    }
}


void heap_sort(int *target, int len) {
    int finish_index = len / 2;
    while (finish_index >= 1) {
        shifting(target, finish_index, len);
        finish_index--;
    }
    finish_index = len;
    while (finish_index > 1) {
        swap(&target[1], &target[finish_index]);
        finish_index--;
        shifting(target, 1, finish_index);
    }
}


int main(void) {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int lenth = scanf_mass_int(mass);
    heap_sort(mass, lenth);
    printf_mass_int(mass, lenth);

}
