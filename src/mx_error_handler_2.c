#include "pathfinder.h"

// if one of the remaining liness doesn't match the format above;
void mx_err_invalid_lines(int index) {
    char *line = mx_itoa(index + 1);

    mx_printerr("error: line ");
    mx_printerr(line);
    mx_printerr(" is not valid\n");

    free(line);
}

// if the number received on the first line 
// does no coincide with the number of islands
int mx_err_invalid_number_of_islands(struct s_island **islands, 
                                     int number_of_islands) {
    int i = 0;
    for (; islands[i] != NULL; i++) {}
    if (number_of_islands != i){
        mx_printerr("error: invalid number of islands\n");
        return 1;
    }
    return 0;
}
