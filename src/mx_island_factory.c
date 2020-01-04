#include "pathfinder.h"

struct s_island* mx_create_island(char *name, int num_of_bridges) {
    struct s_island* island = (struct s_island*) 
                               malloc(sizeof(struct s_island));
    
    island->name = (char*) malloc(sizeof(char) * (mx_strlen(name) + 1));
    mx_strcpy(island->name, name);
    island->paths = (struct s_path**) malloc((num_of_bridges + 1)
                    * sizeof(struct s_path*));
    island->path_count = 0;
    island->paths[0] = NULL;

    island->b_routes = (struct s_path**) malloc((num_of_bridges + 1)
                          * sizeof(struct s_path*));
    island->best_routes_count = 0;
    island->b_routes[0] = NULL;
    return island;
}

void mx_free_islands(struct s_island** islands) {
    int i;

    for (i = 0; islands[i] != NULL; i++) {
        free(islands[i]->name);
        mx_free_paths(islands[i]->paths);
        mx_free_paths(islands[i]->b_routes);
        free(islands[i]);
    }
    free(islands);
}

struct s_island* mx_get_island(char *name, struct s_island **islands,
                               int num_of_bridges) {
    int i;

    for (i = 0; islands[i] != NULL; i++) {
        if (mx_strcmp(islands[i]->name, name) == 0) {
            return islands[i];
        } 
    }
    islands[i] = mx_create_island(name, num_of_bridges);
    islands[i + 1] = NULL;
    return islands[i];
}

void mx_fill_islands(t_bridge **bridges, struct s_island **islands,
                     int num_of_bridges) {
    struct s_island *island1 = NULL;
    struct s_island *island2 = NULL;

    for (int index = 0; index < num_of_bridges; index++){
        island1 = mx_get_island(bridges[index]->islandName1,
                                islands, num_of_bridges);
        island2 = mx_get_island(bridges[index]->islandName2,
                                islands, num_of_bridges);
        island1->paths[island1->path_count] = mx_create_path(island2, 
                                        bridges[index]->length_of_bridge);
        island1->path_count = island1->path_count + 1;
        island1->paths[island1->path_count] = NULL;
        island2->paths[island2->path_count] = mx_create_path(island1, 
                                        bridges[index]->length_of_bridge);
        island2->path_count = island2->path_count + 1;
        island2->paths[island2->path_count] = NULL;
    }
}
