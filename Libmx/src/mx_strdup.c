#include "libmx.h"

char *mx_strdup(const char *str){
    char *duplicate = mx_strnew(mx_strlen(str));
    
    if (duplicate == NULL){
        return NULL;
    }
    return mx_strcpy(duplicate, str);
}
