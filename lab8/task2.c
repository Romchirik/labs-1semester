#include <stdio.h>

#define N 10000

int crossword[10][10] = {0};
int result[10] = {0};

int count_dots_horizontal(int y, int lenth) {
    int counter = 0;
    int len = 0;
    int flag = 0;
    for (int i = 0; i < lenth; i++) {
        if (crossword[y][i] != 0) {
            counter++;
            flag = 1;
        } else {
            if (flag) {
                flag = 0;
                result[len] = counter;
                len++;
                counter = 0;
            }
        }
    }
    if (counter != 0) {
        result[len] = counter;
        len++;
    }
    return len;
};

int count_dots_vertical(int x, int lenth) {
    int counter = 0;
    int len = 0;
    int flag = 0;
    for (int i = 0; i < lenth; i++) {
        if (crossword[i][x] != 0) {
            counter++;
            flag = 1;
        } else {
            if (flag) {
                flag = 0;
                result[len] = counter;
                len++;
                counter = 0;
            }
        }
    }
    if (counter != 0) {
        result[len] = counter;
        len++;
    }
    return len;
};


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y;
    scanf("%d%d", &y, &x);

    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x; i++) {
            scanf("%d", &crossword[j][i]);
        }
    }

    for (int i = 0; i < y; i++) {
        int len = count_dots_horizontal(i, x);
        for (int j = 0; j < len; j++) {
            printf("%d ", result[j]);
        }
        printf("\n");
    }
    for (int i = 0; i < x; i++) {
        int len = count_dots_vertical(i, y);
        for (int j = 0; j < len; j++) {
            printf("%d ", result[j]);
        }
        printf("\n");
    }
}