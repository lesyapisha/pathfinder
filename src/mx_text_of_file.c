#include "pathfinder.h"

static void fix_last_line(char ***lines_ptr) {
    char **lines = *lines_ptr;
    int i = 0;
    char *prev_str;

    while(lines[i] != NULL) {
        prev_str = lines[i];
        i++;
    }
    if (i != 0 && mx_strcmp(prev_str, "") == 0) {
        free(lines[i - 1]);
        lines[i - 1] = NULL;
    }
}

int mx_text_of_file(int argc, char *argv[], char ***lines) {
    char *text_of_file = NULL;

    if (mx_err_valid_command_lines(argc)) {
        return 1;
    }
    //  error if the file doesn't exist
    if (mx_err_no_file(argv[1])) {
        return 1;
    }
    text_of_file = mx_file_to_str(*(argv + 1));
    *lines = mx_correct_strsplit(text_of_file, '\n');
    fix_last_line(lines);
    //  error if the file is empty
    if (mx_err_file_is_empty(text_of_file, argv[1])) {
        free(text_of_file);
        return 1;
    }
    free(text_of_file);
    return 0;
}
