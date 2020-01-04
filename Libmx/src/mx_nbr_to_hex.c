#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr){
    unsigned long nbr_copy = nbr;
    int length;
    for (length = 0; nbr_copy > 0; length++){
        nbr_copy = nbr_copy / 16;
    }
    char hex[length + 1];
    char *h = hex;
    for (int i = length - 1; i >= 0; i--){
        int temp = nbr % 16;
        if (temp >= 0 && temp <= 9)
            hex[i] = temp + '0';
        else if (temp >= 10 && temp <= 15)
            hex[i] = temp + 87;
        nbr = nbr / 16;
    }
    hex[length] = '\0';
    return h;
}
