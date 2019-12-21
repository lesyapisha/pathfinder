#include "pathfinder.h"
// #include "path.h"

struct s_island* mx_create_island(char *name);

static int execute(t_bridge** array_of_bridges, int num_of_bridges, 
                   int number_of_islands) {
    struct s_island **islands = (struct s_island**) malloc((2 * num_of_bridges + 1)
                                 * sizeof(struct s_island*));
    
    islands[0] = NULL;
    //filling array of islands
    mx_fill_islands(array_of_bridges, islands, num_of_bridges);
    mx_free_bridges(array_of_bridges, num_of_bridges);
    // if the number received on the first line does not coincide with 
    // the number of islands
    if (mx_err_invalid_number_of_islands(islands, number_of_islands)) {
        return 0;
    }
    mx_algo(islands, number_of_islands);
    mx_free_islands(islands, number_of_islands);
    // system("leaks pathfinder");
    return 0;
}

int main(int argc, char *argv[]) {
    char **lines = NULL;
    int num_of_bridges = 0;

    if (mx_text_of_file(argc, argv, &lines)){
        return 0;
    }
    // creation array_of_bridges
    num_of_bridges = mx_size_of_file(lines);
    t_bridge **array_of_bridges = (t_bridge**) malloc((num_of_bridges + 1) 
                                   * sizeof(t_bridge*));
    if (mx_fill_bridges(lines, array_of_bridges)) {
        return 0;
    }
    // system("leaks a.out");
    return execute(array_of_bridges, num_of_bridges, mx_atoi(lines[0]));
}
