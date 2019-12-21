#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace){
    char *result;
    int count;
    int i = 0;
    int replace_len = mx_strlen(replace);
    int sub_len = mx_strlen(sub);
    count = mx_count_substr(str, sub);

    result = (char *)malloc(count* (replace_len - sub_len) + 1);

    while (*str) {
        if (mx_strstr(str, sub) == str) {
            mx_strcpy(&result[i], replace);
            i += replace_len;
            str += sub_len;
        }
        else
        result[i++] = *str++;
    }
    result[i] = '\0';
    return result;
}
