#include "libmx.h"

char *mx_strtrim(const char *str){
    if (str == NULL) {
        return NULL;
    }
    int pos_begin = 0;
    int length = mx_strlen(str);
    int pos_end = length - 1;

    //set first symbol not space position
    for (int i = 0; i <= length; i++) {
        if (mx_isspace(str[i])) {
            pos_begin++;
        } else {
            break;
        }
    }
    //set last symbol before space position
    for (int i = length - 1; i >= 0; i--) {
        if (mx_isspace(str[i])){
            pos_end--;
        } else {
            break;
        }
    }
    //return empty string if no symbols in string
    if (pos_begin == length || pos_end == -1)  {
        char *string = "";
        return string;
    }

    //copy string 
    char newstring_length = pos_end - pos_begin + 1;
    char *newstring = mx_strnew(newstring_length);
    int j = 0;

    for (int i = pos_begin; i != pos_end + 1; i++) {
        newstring[j] = str[i];
        j++;
    }

    newstring[j] = '\0';
    return newstring;
}
