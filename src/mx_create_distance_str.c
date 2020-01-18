#include "pathfinder.h"

static char *create_distance_substr(char *new_dist, char *old_dist,
                                    long length_of_bridge, 
                                    long shortest_path){
    new_dist = mx_ms_strjoin(
            old_dist, mx_itoa(length_of_bridge));
    new_dist = mx_ms_strjoin(new_dist,
    mx_strdup(" = "));
    new_dist = mx_ms_strjoin(new_dist,
    mx_itoa(shortest_path));
    return new_dist;
}

char *mx_cr_dist_str(t_pair *pair, struct s_path *route,
                  char *old_dist){
    char *new_dist = NULL;

    if (mx_strcmp(pair->second->name, route->to->name) == 0) {
        if (mx_strcmp(old_dist, "\0") == 0){
            new_dist = mx_itoa(pair->second->shortest_path);
            free(old_dist);
        } else {
            new_dist = create_distance_substr(new_dist, old_dist,
                    route->length_of_bridge, pair->second->shortest_path);
        }
    } else {
        new_dist = mx_ms_strjoin(old_dist, mx_itoa(route->length_of_bridge));
        new_dist = mx_ms_strjoin(new_dist, mx_strdup(" + "));
    }
    return new_dist;
}
