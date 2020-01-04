#include "pathfinder.h"

static char *create_distance_substr(char *new_dist, char *old_dist,
                                    long length_of_bridge, 
                                    long shortest_path){
    new_dist = mx_ms_strjoin(
    mx_itoa(length_of_bridge), old_dist);
    new_dist = mx_ms_strjoin(new_dist,
    mx_strdup(" = "));
    new_dist = mx_ms_strjoin(new_dist,
    mx_itoa(shortest_path));
    return new_dist;
}

char *mx_cr_dist_str(t_pair *pair, struct s_path *route,
                  char *old_dist, struct s_island *current){
    char *new_dist = NULL;

    if (mx_strcmp(pair->first->name, route->to->name) == 0) {
        if (mx_strcmp(old_dist, "\0") == 0){
            new_dist = mx_itoa(current->shortest_path);
            free(old_dist);
        } else {
            new_dist = create_distance_substr(new_dist, old_dist,
                    route->length_of_bridge, pair->second->shortest_path);
        }
    } else {
        new_dist = mx_ms_strjoin(
        mx_itoa(route->length_of_bridge), old_dist);
        new_dist = mx_ms_strjoin(mx_strdup(" + "),
                                              new_dist);
    }
    return new_dist;
}
