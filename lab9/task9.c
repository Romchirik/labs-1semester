#include <stdio.h>

int main() {

    char ch;
    char extra_ch;
    int block_commennt_flag = 0, string_coment_flag = 0, read_flag = 1;
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    while (!feof(input)) {
        if (read_flag) {
            if(fscanf(input, "%c", &ch) == EOF){
                break;
            }
        } else {
            read_flag = 1;
        }

        if ((ch == '/') && (!block_commennt_flag) && (!string_coment_flag)) {
            fscanf(input, "%c", &extra_ch);
            if ((extra_ch == '/') || (extra_ch == '*')) {
                if (extra_ch == '/') {
                    string_coment_flag = 1;
                    continue;
                }

                if (extra_ch == '*') {
                    block_commennt_flag = 1;
                    continue;
                }
            } else {
                fprintf(output, "%c%c", ch, extra_ch);
                continue;
            }

        }
        if ((string_coment_flag) || (block_commennt_flag)) {
            if (ch == '\n') {
                string_coment_flag = 0;
                fputc('\n', output);
                continue;
            } else {
                if (ch == '*') {
                    fscanf(input, "%c", &extra_ch);
                    if (extra_ch == '/') {
                        block_commennt_flag = 0;
                        continue;
                    } else {
                        ch = extra_ch;
                        read_flag = 0;
                        continue;
                    }
                } else {
                    continue;
                }
            }
        } else {
            fputc(ch, output);
        }

    }

    fclose(input);
    fclose(output);

}