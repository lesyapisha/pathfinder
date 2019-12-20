#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int length_haystack = mx_strlen(haystack);
    int length_needle = mx_strlen(needle);
    if (length_haystack < length_needle)
        return NULL;
    if (!length_needle)
        return (char *)haystack;
    for (; ((haystack = mx_strchr(haystack, needle[0])) != NULL); haystack++) {
        if (!mx_strncmp(haystack, needle, length_needle)) {
            return (char *)haystack;
        }
    }
    return 0;
}
