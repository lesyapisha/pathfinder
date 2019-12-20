#include "../Libmx/src/libmx.h"

static bool str_is_alpha(char *str) {
    int index = 0;
    while (str[index] != '\0') {
        if (!mx_isalpha(str[index])) {
            return false;
        }
        index++;
    }
    return true;
}

static int check_lines(char **split_by_hyphen, char **split_by_coma) {
    int index = 0;

//  check first word in line
    if (!str_is_alpha(split_by_hyphen[0])) {
        return 1;
    }
//  check second word in line
    if (!str_is_alpha(split_by_coma[0])) {
        return 1;
    }
//  check digit
    while (split_by_coma[1][index] != '\0') {
        if (!mx_isdigit(split_by_coma[1][index])) {
            return 1;
        }
        index++;
    }
    return 0;
}

// check the number of allowed delimeters
static int check_delims(char* dup) {
    int num_of_hyphen = 0;
    int num_of_coma = 0;

    while (*dup != '\0') {
        if (*dup == '-') {
            num_of_hyphen++;
        } else if (*dup == ',') {
            num_of_coma++;
        }
        dup++;
    }
    if (num_of_hyphen != 1 || num_of_coma != 1) {
        return 1;
    }
    return 0;
}

static t_bridge* create_bridge_instance(char* islandName1, char* islandName2, int length_of_bridge) {
    t_bridge* bridge = (t_bridge*) malloc(sizeof(t_bridge));

    bridge->islandName1 = (char*) malloc(sizeof(char) * (mx_strlen(islandName1) + 1));
    bridge->islandName1 = mx_strcpy(bridge->islandName1, islandName1);

    bridge->islandName2 = (char*) malloc(sizeof(char) * (mx_strlen(islandName2) + 1));
    bridge->islandName2 = mx_strcpy(bridge->islandName2, islandName2);

    bridge->length_of_bridge = length_of_bridge;

    return bridge;
}

t_bridge* mx_split_line(char *line) {
    char** split_by_hyphen = mx_strsplit(line, '-');
    char** split_by_coma = mx_strsplit(split_by_hyphen[1], ',');
    char* dup = line;

    if (check_delims(dup)) {
        return NULL;
    }
    if (check_lines(split_by_hyphen, split_by_coma)) {
        return NULL;
    }
    
    return create_bridge_instance(split_by_hyphen[0], split_by_coma[0], mx_atoi(split_by_coma[1]));
}
