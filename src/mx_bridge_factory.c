#include "../Libmx/src/libmx.h"

//Rename it to something like fill_bridges
int mx_fill_bridges(char **lines, t_bridge** array_of_bridges){
    int index = 1;

    if (mx_err_1st_line_invalid(lines[0])){
        return 1;
    }
    //  error if one of the remaining liness doesn't match the format above
    while (lines[index]) {
        if (mx_err_invalid_lines(lines[index], index)){
            return 1;
        }
        //filling array of bridges
        array_of_bridges[index - 1] = mx_split_line(lines[index]);
        index++;
    }
    return 0;
}

void mx_free_bridges(t_bridge** bridges, int num_of_bridges) {
	int i;

	for (i = 0; i< num_of_bridges; i++) {
		free(bridges[i]->islandName1);
		free(bridges[i]->islandName2);
		free(bridges[i]);
	}
	free(bridges);
}
