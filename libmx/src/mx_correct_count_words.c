#include "libmx.h"

int mx_correct_count_words(const char *str, char c) {
    int words = 0;
    int del_count = 0;
    
    if (!str) {
        return -1;
    }
    while (*str) {
        if (*str == c) {
            del_count++;
        }
        str++;
    }
    words = del_count + 1;
    return words;
}
