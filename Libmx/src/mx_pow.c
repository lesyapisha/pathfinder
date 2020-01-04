#include "libmx.h"

double mx_pow(double n, unsigned int pow){
    unsigned int i; 
    double result = 1;

    if (pow <= 0) {
        return 1;
    }
    for (i = 0; i < pow; i++){
        result *= n;
    }
    return result;
}
