#include "libmx.h"

int mx_atoi(const char *str) {
    int i = 0;
    int flag = 1;
    int result = 0;
    if (mx_isspace(str[i])) {
        return 0;
    }
    if (str[i] == '-') {
        flag = -1;
        i++;
    }
    if (str[i] == '+') {
        flag = 1;
        i++;
    }

    while (str[i]) {
        if (mx_isspace(str[i]) || !mx_isdigit(str[i])) {
            return -1;
        }
        result = result * 10 + str[i] - '0';
        i++;
    }
    return result * flag;
}
