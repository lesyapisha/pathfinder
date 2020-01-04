#include "pathfinder.h"

static void clear_routes(struct s_path** paths) {
    int i;

    for (i = 0; paths[i] != NULL; i++) {
        free(paths[i]);
        paths[i] = NULL;
    }
}

static void add_best_route(struct s_island *island,
                           struct s_island *to_island,
                           struct s_path *path) {
    to_island->b_routes[to_island->best_routes_count]
    = mx_create_path(island, path->length_of_bridge);
    to_island->b_routes[to_island->best_routes_count + 1] = NULL;
    to_island->best_routes_count = to_island->best_routes_count + 1;
}

static void init_best_routes(struct s_island *island, 
                             struct s_island *to_island,
                             struct s_path *path) {
    to_island->shortest_path = island->shortest_path 
                             + path->length_of_bridge;
    clear_routes(to_island->b_routes);
    to_island->best_routes_count = 0;
    add_best_route(island, to_island, path);
}

void mx_process_island(struct s_island *island,
                       int number_of_islands) {
    int i = 0;
    struct s_path* path = NULL;
    struct s_island* to_island = NULL;

    while (island->paths[i] != NULL) {
        path = island->paths[i];
        to_island = path->to;
        if (island->shortest_path + path->length_of_bridge
            < to_island->shortest_path 
            || to_island->shortest_path == -1) {
            init_best_routes(island, to_island, path);
            mx_process_island(to_island, number_of_islands);
        } else if (island->shortest_path + path->length_of_bridge
                   == to_island->shortest_path) {
            add_best_route(island, to_island, path);
        }
        i++;
    }
}

void mx_algo(struct s_island **islands, int number_of_islands) {
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < number_of_islands; i++) {
        k = 0;
        while (islands[k] != NULL) {
            islands[k]->shortest_path = -1;
            clear_routes(islands[k]->b_routes);
            islands[k]->best_routes_count = 0;
            islands[k]->b_routes[0] = NULL;
            k++;
        }
        islands[i]->shortest_path = 0;
        mx_process_island(islands[i], number_of_islands);
        for (j = i + 1; j < number_of_islands; j++) {
            mx_output_result(islands[i], islands[j]);
        }
    }
}
