#include "pathfinder.h"

static void free_bridge(t_bridge* bridge) {
    free(bridge->islandName1);
    free(bridge->islandName2);
    free(bridge);
}

int mx_fill_bridges(char **lines, t_bridge **array_of_bridges) {
    int index = 1;

    if (mx_err_1st_line_invalid(lines[0])) {
        return 1;
    }
    //  error remaining liness doesn't match the format above
    while (lines[index]) {
        t_bridge* bridge = mx_split_line(lines[index]);
        if (bridge == NULL){
            array_of_bridges[index - 1] = NULL;
            mx_err_invalid_lines(index);
            return 1;
        }
        array_of_bridges[index - 1] = bridge;
        index++;
    }
    array_of_bridges[index - 1] = NULL;
    return 0;
}

void mx_free_bridges(t_bridge** bridges) {
    int i;

    for (i = 0; bridges[i] != NULL; i++) {
        free_bridge(bridges[i]);
    }
    free(bridges);
}
