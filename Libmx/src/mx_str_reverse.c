#include "libmx.h"

void mx_str_reverse(char *s) {
    int len = mx_strlen(s);
    int num_of_per = len/2;
    int i;
    for (i = 0; i < num_of_per; i++) {
        mx_swap_char(&s[i], &s[len - i - 1]);
    }
}
