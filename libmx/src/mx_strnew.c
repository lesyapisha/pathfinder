#include "libmx.h"

char *mx_strnew(const int size){
    int const max_int = 2147483646;

    if ((size > max_int) || (size < 0)){
        return NULL;
    }

    char *str = (char*) malloc(sizeof(char) * (size + 1));

    if (str == NULL){
        return NULL;
    }

    for (int i = 0; i <= size; i++){
        str[i] = '\0';
    }
    return str;
}
