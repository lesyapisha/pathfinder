#include "pathfinder.h"

int mx_text_of_file(int argc, char *argv[], char ***lines) {
    char *text_of_file = NULL;
    
    //  error if there are an invalid number of command-lines arguments
    if (mx_err_valid_command_lines(argc)) {
        return 1;
    }
    //  error if the file doesn't exist
    if (mx_err_no_file(argv[1])) {
        return 1;
    }
    text_of_file = mx_file_to_str(*(argv + 1));
    *lines = mx_strsplit(text_of_file, '\n');    
    //  error if the file is empty
    if (mx_err_file_is_empty(text_of_file, argv[1])) {
        free(text_of_file);
        return 1;
    }
    free(text_of_file);
    return 0;
}
