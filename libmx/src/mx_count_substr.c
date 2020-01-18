#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    if (!str || !sub) {
        return -1;
    }
    char *str_copy = mx_strstr(str, sub);
    int length_sub = mx_strlen(sub);
    if (!length_sub)
        return -1;
    while (str_copy != 0) {
        str_copy += length_sub;
        str_copy= mx_strstr(str_copy, sub);
        count++;
    }
    if (count == 0)
        return -1;
    return count;
}
