#include <stdio.h>
#include <stdlib.h>

#define get_start_string(stage) (stage + 1) * (stage + 2) / 2 - 2
#define get_base_stars_amount(string) (string) * 2 - 1
#define get_middle_pos(last) (get_base_stars_amount(get_start_string(last)) + (last + 1) * 2 + get_additional_stars_amount(last)) / 2
#define get_door_size(last) (last % 2 == 1? last : last - 1)
#define ABS(a) ((a) < 0 ? -(a) : (a))

int get_additional_stars_amount(int stage) {
    if (stage == 0) {
        return 0;
    } else if (stage % 2 == 1) {
        return get_additional_stars_amount(stage - 1) + (stage - 1) * 2;
    } else {
        return get_additional_stars_amount(stage - 1) + stage * 2;
    }
}

void print_stage(int stage, int last) {

    for (int i = 1; i <= stage + 2; i++) {

        if (stage == last && (last + 3 - i <= get_door_size(last))) {

            int current_pos = -1;

            for (int j = 0;
                 j <
                 (get_base_stars_amount(get_start_string(last)) + (last + 1) * 2 +
                  get_additional_stars_amount(last)) /
                 2 -
                 (get_base_stars_amount(get_start_string(stage)) + get_additional_stars_amount(stage) +
                  (i - 1) * 2) /
                 2;
                 j++) {
                putchar(' ');
                ++current_pos;
            }

            putchar('/');
            ++current_pos;

            for (int j = 0;

                 j <
                 get_base_stars_amount(get_start_string(stage)) + get_additional_stars_amount(stage) + (i - 1) * 2;

                 j++) {


                if (ABS(get_middle_pos(last) - current_pos) <= get_door_size(last) / 2) {

                    if (last >= 5 && current_pos - get_middle_pos(last) == get_door_size(last) / 2 - 1&&
                        (last + 2 - i) == get_door_size(last) / 2) {
                        putchar('$');
                        ++current_pos;
                    } else {
                        putchar('|');
                        ++current_pos;
                    }
                } else {
                    putchar('*');
                    ++current_pos;
                }
            }

            putchar('\\');
            putchar('\n');

        } else {

            for (int j = 0;
                 j <
                 (get_base_stars_amount(get_start_string(last)) + (last + 1) * 2 + get_additional_stars_amount(last)) /
                 2 -
                 (get_base_stars_amount(get_start_string(stage)) + get_additional_stars_amount(stage) + (i - 1) * 2) /
                 2;
                 j++) {
                putchar(' ');
            }

            putchar('/');

            for (int j = 0;

                 j < get_base_stars_amount(get_start_string(stage)) + get_additional_stars_amount(stage) + (i - 1) * 2;

                 j++) {
                putchar('*');
            }

            putchar('\\');
            putchar('\n');
        }
    }
}

int main(int argc, char *argv[]) {
    int last = atoi(argv[1]);
    for (int i = 1; i <= last; i++) {
        print_stage(i, last);
    }
    return 0;
}