#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    static int count = 0;
    if (arr == NULL) {
        return -1;
    }
    int min = left;
    int max = right;
    int mid = (left + right) / 2;

    while (min < max) {
        if (mx_strlen(arr[min]) < mx_strlen(arr[mid])) {
            min++;
        }
        if (mx_strlen(arr[mid]) <= mx_strlen(arr[max])) {
            max--;
        }
        if (min < max) {
            char *temp = arr[min];
            arr[min] = arr[max];
            arr[max] = temp;
            count++;
        }
        min++;
        max--;
    }
    if (left < max) {
        mx_quicksort(arr, left, max);
    }
    if (right > min) {
        mx_quicksort(arr, min, right);
    }
    return count;
}
