#include "pathfinder.h"

void mx_clear_routes(struct s_path** paths) {
    int i;

    for (i = 0; paths[i] != NULL; i++) {
        free(paths[i]);
        paths[i] = NULL;
    }
}

void mx_prepare_islands(struct s_island **islands, int number_of_islands) {
    int i;

    for (i = 0; i < number_of_islands; i++) {
        mx_clear_routes(islands[i]->f_routes);
    }
}
