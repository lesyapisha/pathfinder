#include "pathfinder.h"

static int check_distance(char *s) {
    if (mx_atoi(s) < 0 || mx_atoi(s) > 2147483647) {
        return 1;
    }
    return 0;
}

static void free_string_array(char **array) {
    int i;

    for (i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

static int mx_valid_lines(char **split_by_hyphen,
                          char **split_by_coma, char *dup) {
    if (mx_check_delims(dup)) {
        free_string_array(split_by_hyphen);
        free_string_array(split_by_coma);
        return 1;
    }
    if (mx_check_lines(split_by_hyphen, split_by_coma)) {
        free_string_array(split_by_hyphen);
        free_string_array(split_by_coma);
        return 1;
    }
    if (check_distance(split_by_coma[1])) {
        free_string_array(split_by_hyphen);
        free_string_array(split_by_coma);
        return 1;
    }
    return 0;
}

t_bridge *mx_split_line(char *line) {
    char **split_by_hyphen = mx_correct_strsplit(line, '-');
    char **split_by_coma = mx_correct_strsplit(split_by_hyphen[1], ',');
    char *dup = line;
    
    if(mx_valid_lines(split_by_hyphen, split_by_coma, dup)){
        return NULL;
    }
    t_bridge* bridge = mx_create_bridge_instance(mx_strdup(split_by_hyphen[0]),
                                              mx_strdup(split_by_coma[0]),
                                              mx_atoi(split_by_coma[1]));
    free_string_array(split_by_hyphen);
    free_string_array(split_by_coma);
    return bridge;
}
