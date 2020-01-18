#include "libmx.h"

char *mx_itoa(int number){
    
    int temp = number;
    int len = 0;
    
    int i = 0;
    bool isNegative = false;
    
    while(temp != 0){
        temp /= 10;
        ++len;
    }
    char *str = mx_strnew(len + 1);
    
    //Handle 0 if empty string is printed for 0
    if (number == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (number < 0) {
        isNegative = true;
        number = -number;
    }
    while (number != 0) {
        int rem = number%10;
        str[i++] = rem + '0';
        number = number/10;
    }

    // If number is negative, append '-' 
    if (isNegative) {
        str[i++] = '-';
    }
    str[i] = '\0';
    
    mx_str_reverse(str);
    return str;
}
