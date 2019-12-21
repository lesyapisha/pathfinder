#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim){
    int i = 0;
    if (delim != NULL || arr != NULL) {
        while (arr[i] != NULL){
            mx_printstr(arr[i]);
            if (arr[i + 1] == NULL) {
                mx_printstr("\n");
            } else {
                mx_printstr(delim);
            }
            i++;
        }
    }
}
