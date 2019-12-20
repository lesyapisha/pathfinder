#include <stdbool.h>

bool mx_isalpha(int c) {
    return (c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z');
}
