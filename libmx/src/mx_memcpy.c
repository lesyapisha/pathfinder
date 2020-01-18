#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *dst_copy = dst;
    const char *src_copy = src;

    while (n--) {
        *dst_copy = *src_copy;
        dst_copy++;
        src_copy++;
    }
    return dst;
}
