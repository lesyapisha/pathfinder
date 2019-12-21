#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count){
    int lower = 0;
    int mid, upper = size - 1;
    *count = 0;
    while (lower <= upper) {
        (*count)++;
        mid = lower + (upper - lower) / 2;
        if (mx_strcmp(arr[mid], s) == 0) {
            return mid;
        } else if (mx_strcmp(arr[mid], s) > 0) {
            upper = mid -1;
        } else {
            lower = mid + 1;
        }
    }
    *count = 0;
    return -1;
}
