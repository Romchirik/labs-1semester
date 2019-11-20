#include <stdio.h>

int list[1000] = {0};

int sort(int *target, int n, int start_index) {
    int left = start_index, right = n - 1;
    int flag = 1;

    while ((left < right) && (flag)) {
        flag = 0;

        for (int i = left; i < right; i++) {
            if (target[i] > target[i + 1]) {
                int buffer = target[i];
                target[i] = target[i + 1];
                target[i + 1] = buffer;
                flag = 1;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (target[i - 1] > target[i]) {
                int buffer = target[i];
                target[i] = target[i - 1];
                target[i - 1] = buffer;
                flag = 1;
            }
        }
        left++;
    }
}

int next(int *target, int n) {

    int index = -1;
    for (int i = n - 1; i > 0; i--) {
        if (target[i] > target[i - 1]) {
            index = i - 1;
            break;
        }
    }

    if (index == -1) {
        for (int i = 0; i < n; i++) {
            target[i] = i + 1;
        }
        return 0;
    } else {
        int index2 = index + 1;
        int min = target[index + 1];

        for(int i = index; i < n; i ++){
            if ((target[i] > target[index]) && (target[i] < min)){
                min = target[i];
                index2 = i;
            }
        }

        int buffer = target[index];
        target[index] = target[index2];
        target[index2] = buffer;

        sort(target, n, index + 1);

        return 0;
    }

}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    next(list, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    return 0;
}