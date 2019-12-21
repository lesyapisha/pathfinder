#include "../Libmx/src/libmx.h"

//Rename it to something like fill_bridges
int mx_fill_bridges(char **lines, t_bridge** array_of_bridges){
    int index = 1;

    if (mx_err_1st_line_invalid(lines[0])){
        return 1;
    }

    //  error if one of the remaining liness doesn't match the format above
    while (lines[index]) {
        t_bridge* bridge = mx_split_line(lines[index]);
        if (bridge == NULL){
            mx_err_invalid_lines(index);
            return 1;
        }
        //filling array of bridges
        array_of_bridges[index - 1] = bridge;
        index++;
    }
    array_of_bridges[index - 1] = NULL;

    return 0;
}

void mx_free_bridges(t_bridge** bridges) {
	int i;

    for (i = 0; bridges[i] != NULL; i++) {
        free(bridges[i]->islandName1);
        free(bridges[i]->islandName2);
        free(bridges[i]);
    }

	free(bridges);
}
