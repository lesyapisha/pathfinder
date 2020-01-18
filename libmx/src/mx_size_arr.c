#include "libmx.h"

int mx_size_arr(char** arr){
    int size = 0;
    
    while (arr[size]){
        size++;
    }
    return size;
}
