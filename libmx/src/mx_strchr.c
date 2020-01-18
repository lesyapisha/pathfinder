#include "libmx.h"

char *mx_strchr(const char *s, int c) {
    char a;
    a = c;
    for (;; ++s) {
        if (*s == a)
            return ((char *)s);
        if (*s == '\0')
            return (NULL);
    }
}
