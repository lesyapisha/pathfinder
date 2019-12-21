#include "pathfinder.h"

//  error if there are an invalid number of command-lines arguments
int mx_err_valid_command_lines(int argc) {
    if (argc != 2){
        mx_printstr("usage: ./pathfinder [filename]\n");
        return 1;
    }
    return 0;
}

// error if the file doesn't exist
int mx_err_no_file(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        mx_printstr("error: file ");
        mx_printstr(filename);
        mx_printstr(" does not exist\n");
        return 1;
    }
    return 0;
}

//  error if the file is empty
int mx_err_file_is_empty(char *text_of_file, char *filename) {
    if (text_of_file == '\0') {
        mx_printstr("error: file ");
        mx_printstr(filename);
        mx_printstr(" is empty\n");
        return 1;
    }
    return 0;
}

//  error if 1st line is invalid
int mx_err_1st_line_invalid(char *first_line) {
    int number_of_islands = mx_atoi(first_line);

    if (number_of_islands == -1) {
        mx_printstr("error: line 1 is not valid\n");
        return 1;
    }
    if (number_of_islands == 0) {
        return 1;
    }
    return 0;
}

// if one of the remaining liness doesn't match the format above;
void mx_err_invalid_lines(int index) {
    char *line = mx_itoa(index + 1);

    mx_printstr("error: line ");
    mx_printstr(line);
    mx_printstr(" is not valid\n");

    free(line);
}

// if the number received on the first line does no coincide with the number of islands
int mx_err_invalid_number_of_islands(struct s_island **islands, int number_of_islands) {
    int i = 0;
    for (; islands[i] != NULL; i++) {}
    if (number_of_islands != i){
        mx_printstr("error: invalid number of islands\n");
        return 1;
    }
    return 0;
}
