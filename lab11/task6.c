//thanks https://vk.com/theabbit
//кстати у него есть свой гитхаб: https://github.com/abbit
//там есть некоторые алгоритмы, обязательно прочекайте

#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int binary_search(const int *nums, int nums_size, int target)
{
    int left_border = 0;
    int right_border = nums_size - 1;

    int target_position = (left_border + right_border) / 2;

    while (nums[target_position] != target)
    {
        if (left_border > right_border)
        {
            return -1;
        }

        if (nums[target_position] < target)
        {
            left_border = target_position + 1;
        }
        else
        {
            right_border = target_position - 1;
        }

        target_position = (left_border + right_border) / 2;
    }

    return target_position;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int A_length;
    scanf("%d", &A_length);

    int *A = malloc(A_length * sizeof(int));

    for (int i = 0; i < A_length; ++i) {
        scanf("%d", &A[i]);
    }

    qsort(A, A_length, sizeof(int), compare_ints);

    int B_length;
    scanf("%d", &B_length);

    int *B = malloc(B_length * sizeof(int));

    for (int i = 0; i < B_length; ++i) {
        scanf("%d", &B[i]);
    }

    qsort(B, B_length, sizeof(int), compare_ints);

    int *res = malloc(A_length * sizeof(int));
    int res_len = 0;

    for (int i = 0; i < A_length; ++i) {
        int a = A[i];

        if (a < B[0] || a > A[A_length - 1])
        {
            res[res_len] = a;
            res_len++;
            continue;
        }

        if (binary_search(B, B_length, a) == -1)
        {
            res[res_len] = a;
            res_len++;
        }
    }

    if(res_len == 0)
    {
        printf("0");
        return 0;
    }

    int *unique_arr = malloc(res_len * sizeof(int));
    unique_arr[0] = res[0];
    int unique_arr_len = 1;

    for (int i = 1; i < res_len; ++i) {
        if (res[i] != res[i -1])
        {
            unique_arr[unique_arr_len] = res[i];
            unique_arr_len++;
        }
    }

    printf("%d\n", unique_arr_len);

    for (int i = 0; i < unique_arr_len; ++i) {
        printf("%d ", unique_arr[i]);
    }

    return 0;
}