#include "pathfinder.h"

t_pair *mx_create_pair(struct s_island *first, struct s_island *second) {
    t_pair *pair = (t_pair *) malloc(sizeof(t_pair) + 2
                                    * sizeof(struct s_island));
    pair->first = first;
    pair->second = second;
    return pair;
}

void mx_free_pair(t_pair *pair) {
    free(pair);
}
