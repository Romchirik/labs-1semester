#include <stdio.h>

char list[1000] = {0};

int sort(char *target, int n, int start_index) {
    int left = start_index, right = n - 1;
    int flag = 1;

    while ((left < right) && (flag)) {
        flag = 0;

        for (int i = left; i < right; i++) {
            if ((int)target[i] > (int)target[i + 1]) {
                char buffer = target[i];
                target[i] = target[i + 1];
                target[i + 1] = buffer;
                flag = 1;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if ((int)target[i - 1] > (int)target[i]) {
                char buffer = target[i];
                target[i] = target[i - 1];
                target[i - 1] = buffer;
                flag = 1;
            }
        }
        left++;
    }
}

int next(char *target, int n) {

    int index = -1;
    for (int i = n - 1; i > 0; i--) {
        if ((int)target[i] > (int)target[i - 1]) {
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
        char min = target[index + 1];

        for(int i = index; i < n; i ++){
            if (((int)target[i] > (int)target[index]) && ((int)target[i] < (int)min)){
                min = target[i];
                index2 = i;
            }
        }

        char buffer = target[index];
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
        scanf("%c", &list[i]);
        if (((int)list[i] < 97) || (list[i] > 122))
            i--;
    }

    next(list, n);

    for (int i = 0; i < n; i++) {
        printf("%c ", list[i]);
    }

    return 0;
}