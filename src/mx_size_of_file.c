#include "pathfinder.h"

int mx_size_of_file(char **lines) {
    int index = 1;
    
    while (lines[index]) {
        index++;
    }
    return index - 1;
}
