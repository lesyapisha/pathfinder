#include "pathfinder.h"

static void free_lines(char **lines) {
    int row_index = 0;
    
    while (lines[row_index]) {
        free(lines[row_index]);
        row_index++;
    }
    free(lines);
}

static int execute(t_bridge **array_of_bridges, int num_of_bridges,
                   int number_of_islands) {
    struct s_island** islands = (struct s_island**) 
                                 malloc((2 * num_of_bridges + 1)
                                 * sizeof(struct s_island*));

    islands[0] = NULL;
    mx_fill_islands(array_of_bridges, islands, num_of_bridges);
    mx_free_bridges(array_of_bridges);
    // if the number received on the first line
    // does not coincide with the number of islands
    if (mx_err_invalid_number_of_islands(islands, number_of_islands)) {
        mx_free_islands(islands);
        return 0;
    }
    mx_algo(islands, number_of_islands);
    mx_free_islands(islands);
    return 0;
}

int main(int argc, char *argv[]) {
    char **lines = NULL;
    int num_of_bridges = 0;
    int num_of_islands = 0;

    if (mx_text_of_file(argc, argv, &lines))
        return 0;
    num_of_bridges = mx_size_of_file(lines);
    t_bridge** array_of_bridges = (t_bridge**) malloc((num_of_bridges + 1)
                                                       * sizeof(t_bridge*));
    array_of_bridges[0] = NULL;
    if (mx_fill_bridges(lines, array_of_bridges)) {
        free_lines(lines);
        mx_free_bridges(array_of_bridges);
        return 0;
    }
    num_of_islands = mx_atoi(lines[0]);
    free_lines(lines);
    return execute(array_of_bridges, num_of_bridges, num_of_islands);
}
