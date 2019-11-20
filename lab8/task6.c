#include <stdio.h>
#include <string.h>

char field[250][250] = {0};
int key[250][250] = {0};
int new_key[250][250] = {0};

int check_input_key(int n) {
    for (int y = 0; y < n * 2; y++) {
        for (int x = 0; x < n * 2; x++) {
            int buffer_X = x;
            int buffer_Y = y;
            if (key[buffer_Y][buffer_X] == 1) {
                for (int a = 0; a < 3; a++) {

                    if (key[buffer_X][2 * n - 1 - buffer_Y] == 1) {
                        return 1;
                    }
                    int buffer = buffer_X;
                    buffer_X = 2 * n - 1 - buffer_Y;
                    buffer_Y = buffer;
                }
            }
        }
    }
    return 0;
}

void turn_pi_key(int n) {
    int a = 2 * n;
    for (int y = 0; y < a; y++) {
        for (int x = 0; x < a; x++) {
            new_key[x][2 * n - 1 - y] = key[y][x];
        }
    }
    for (int y = 0; y < a; y++) {
        for (int x = 0; x < a; x++) {
            key[y][x] = new_key[y][x];
        }
    }

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int lenth;
    scanf("%d", &lenth);

    for (int i = 0; i < lenth * 2; i++) {
        for (int j = 0; j < lenth * 2; j++) {
            scanf("%d", &new_key[i][j]);
        }
    }

    for (int i = 0; i < lenth * 2; i++) {
        char buffer[125] = {0};
        scanf("%s", field[i]);

    }

    for (int y = 0; y < 2 * lenth; y++) {
        for (int x = 0; x < 2 * lenth; x++) {
            key[y][x] = new_key[y][x];
        }
    }

    for (int i = 0; i < 4; i++) {
        if (check_input_key(lenth)) {
            printf("No");
            return 0;
        }
        turn_pi_key(lenth);
    }
    for (int a = 0; a < 4; a++) {
        for (int y = 0; y < lenth * 2; y++) {
            for (int x = 0; x < lenth * 2; x++) {
                if (key[y][x] == 1) {
                    printf("%c", field[y][x]);
                }
            }
        }
        turn_pi_key(lenth);
    }

}