#include <stdio.h>
#include <string.h>

char field[10][10][2] = {0};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int width, height;
    int x_robot_pos = 0, y_robot_pos = 0, start_position;
    scanf("%d%d%d", &height, &width, &start_position);
    x_robot_pos = start_position;
    for (int i = 0; i < height; i++) {
        char buffer_string[10];
        scanf("%s", buffer_string);
        for (int j = 0; j < width; j++) {
            field[i][j][0] = buffer_string[j];
        }
    }
    x_robot_pos--;

    int flag = 0, steps_counter = 0, steps_before_loop = 0;

    while (flag == 0) {
        field[y_robot_pos][x_robot_pos][1] = 1;

        switch (field[y_robot_pos][x_robot_pos][0]) {
            case 'N':
                y_robot_pos--;
                break;
            case 'E':
                x_robot_pos++;
                break;
            case 'S':
                y_robot_pos++;
                break;
            case 'W':
                x_robot_pos--;
                break;
        }
        steps_counter++;

        if ((y_robot_pos < 0) || (y_robot_pos == height) || (x_robot_pos < 0) || (x_robot_pos == width)) {
            flag = 1;
        } else{
            if((int) field[y_robot_pos][x_robot_pos][1] == 1){
                flag = 2;
                field[y_robot_pos][x_robot_pos][1] = 2;
                break;
            }
        }

    }

    if (flag == 1) {
        printf("%d step(s) to exit", steps_counter);
    } else {
        x_robot_pos = start_position;
        x_robot_pos--;
        y_robot_pos = 0;

        while (field[y_robot_pos][x_robot_pos][1] != 2){
            switch (field[y_robot_pos][x_robot_pos][0]) {
                case 'N':
                    y_robot_pos--;
                    break;
                case 'E':
                    x_robot_pos++;
                    break;
                case 'S':
                    y_robot_pos++;
                    break;
                case 'W':
                    x_robot_pos--;
                    break;
            }
            steps_before_loop++;
        }
        printf("%d step(s) before a loop of %d step(s)", steps_before_loop, steps_counter - steps_before_loop);
    }

}