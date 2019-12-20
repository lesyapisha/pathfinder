#include "libmx.h"

static int mx_countchr(const char *tgt) {

    int count = 0;

    for (int i = 0; tgt[i] != '\0';) {
        if (!mx_isspace(tgt[i]))
            count++;
        if (mx_isspace(tgt[i])) {
            count++;
            while(mx_isspace(tgt[i]) && tgt[i] != '\0')
                i++;
        }
        i++;
    }
    return count;
}

char *mx_del_extra_spaces(const char *str) {

    int len;
    char *dst = NULL;
    char *tgt = NULL;

    if (!str)
        return NULL;

    tgt = mx_strtrim(str);
    len = mx_countchr(tgt);
    dst = mx_strnew(len);

    for (int i = 0, j = 0; tgt[i] != '\0';) {
        if (!mx_isspace(tgt[i])) {
            dst[j] = tgt[i];
            i++;
            j++;
        }
        if (mx_isspace(tgt[i])) {
            dst[j] = ' ';
            j++;
            while(mx_isspace(tgt[i+1]))
                i++;
            i++;
        }
    }
    free(tgt);
    tgt = NULL;
    return dst;
}
