#include "libmx.h"

void mx_del_strarr(char*** arr) {
    char **dst = *arr;
    
    for (int i = 0; dst[i] != NULL; i++) {
        mx_strdel(&dst[i]);
    }
    free(*arr);
    *arr = NULL;
}
