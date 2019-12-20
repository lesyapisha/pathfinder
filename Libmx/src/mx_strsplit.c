#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    const char *s_dup = s;
    if (s_dup == NULL) {
        return NULL;
    }
    int k = mx_count_words(s_dup, c);
    char **arr = NULL;
    arr = (char **) malloc(sizeof(char* ) * (k + 1));
    for (int i = 0; i < k; i++) {
        int len_word = 0;
        char *count = (char *) s_dup;
        while (len_word == 0 && *count != '\0') {
            count = (char *) s_dup;
            if (*count != c) {
                for(; *(count + len_word) != c && *(count + len_word) != '\0'; len_word++);
            }
            else {
                s_dup++;
            }
        }
        arr[i] = mx_strnew(len_word);
        arr[i] = mx_strncpy(arr[i], s_dup, len_word);
        s_dup += len_word;
    }
    arr[k] = NULL;
    return arr;
}
