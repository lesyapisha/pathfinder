#include "pathfinder.h"

//  error if there are an invalid number of command-lines arguments
int mx_err_valid_command_lines(int argc) {
    if (argc != 2){
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 1;
    }
    return 0;
}

// error if the file doesn't exist
int mx_err_no_file(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        return 1;
    }
    return 0;
}

//  error if the file is empty
int mx_err_file_is_empty(char *text_of_file, char *filename) {
    if (text_of_file == '\0') {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        return 1;
    }
    return 0;
}

//  error if 1st line is invalid
int mx_err_1st_line_invalid(char *first_line) {
    int number_of_islands = mx_atoi(first_line);
    
    if (number_of_islands == -1) {
        mx_printerr("error: line 1 is not valid\n");
        return 1;
    }
    
    return 0;
}
