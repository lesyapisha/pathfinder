#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 == NULL && s2 == NULL) return NULL;
    if (s1 == NULL && s2 != NULL) return mx_strdup(s2);
    if (s1 != NULL && s2 == NULL) return mx_strdup(s1);
    char *str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    str = mx_strcat(str, s1);
    str = mx_strcat(str, s2);
    return str;
}
