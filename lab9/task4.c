/*
Задача решается по другому, считается сумма арифметической прогрессии (теоретическая), по максимальному 
и минимальному элементу, а потом сравнивается с фактической (считается по входным данным), дальше думаю понятно.
Но это решение не работает в общем случае (на нсутс сдается)
Решение ниже медленнее, но работает для всех случаев (на нсутс по времени проходит)
*/

#include <stdio.h>

int ch[100000];

void swap(int *val1, int *val2) {
    int temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void QSort(int *array, int low, int high) {
    int left = low;
    int right = high;
    int pivot = array[(left + right) / 2];
    while (left <= right) {
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;
        if (left <= right) {
            swap(&array[left++], &array[right--]);

        }
    }
    if (low < right)
        QSort(array, low, right);
    if (high > left)
        QSort(array, left, high);
}


int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    int counter = 0, delta = 0;

    while (fscanf(input, "%d", &ch[counter]) == 1) {
        counter++;

    }
    QSort(ch, 0, counter - 1);

    if (counter < 2) {
        printf("NO");
        return 0;
    } else {
        delta = ch[1] - ch[0];
        for (int i = 1; i < counter; i++) {
            if (ch[i] - ch[i - 1] != delta) {
                fprintf(output, "NO");
                return 0;
            }
        }
    }
    fprintf(output, "%d", delta);
    fclose(input);
    fclose(output);
    return 0;
}