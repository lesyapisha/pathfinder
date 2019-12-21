#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *s_copy = s;
    s_copy += n;

    while (n--) {
        if (*s_copy == c) {
            return (void *) s_copy;
        }
        s_copy--;
    }
    return NULL;
}
