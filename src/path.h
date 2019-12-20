// header file path.h

#ifndef LIBMX_H
#define LIBMX_H

#include "../Libmx/src/libmx.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
    char *islandName1;
    char *islandName2;
    int length_of_bridge;
} Bridge;

int mx_atoi(const char *str);
int mx_size_arr(char** arr);
void mx_valid_command_lines(int argc);
bool mx_str_is_alpha(char *str);
Bridge* mx_split_line(char *line);

#endif
