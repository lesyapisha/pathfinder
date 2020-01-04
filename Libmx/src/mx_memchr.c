#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *s_copy = (unsigned char *)s;
    while (n--) {
        if (*s_copy == c) {
            return (void *) s_copy;
        }
        s_copy++;
    }
    return NULL;
}
