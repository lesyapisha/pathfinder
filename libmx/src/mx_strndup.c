#include "libmx.h"

char *mx_strndup(const char *s1, size_t n){
    char *strndup = mx_strnew(n);
    mx_strncpy(strndup, s1, n);
    return strndup;
}
