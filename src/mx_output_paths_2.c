#include "pathfinder.h"

static void add_forward_path(struct s_island *dest_isl,
                          	 struct s_island *src_isl,
                          	 struct s_path *path) {
	int index = 0;
    struct s_path *n_path = mx_create_path(src_isl, 
                            path->length_of_bridge);
    struct s_path *c_path;
    
    while ((c_path = dest_isl->f_routes[index]) != NULL) {
    	if (c_path->to->order == n_path->to->order) {
    		free(n_path);
    		return;
    	}
        if (c_path->to->order > n_path->to->order) {
            dest_isl->f_routes[index] = n_path;
            n_path = c_path;
        }
        index++;
    }
    dest_isl->f_routes[index] = n_path;
    dest_isl->f_routes[index + 1] = NULL;
    dest_isl->best_routes_count = dest_isl->best_routes_count + 1;
}

static void fill_forward_pathes(struct s_island *from, struct s_island *to) {
	int i;

	if(mx_strcmp(from->name, to->name) == 0) {
        return;
    }
	for (i = 0; to->b_routes[i] != NULL; i++) {		
		add_forward_path(to->b_routes[i]->to, to, to->b_routes[i]);
		fill_forward_pathes(from, to->b_routes[i]->to);
	}
}

void mx_output_result(struct s_island* from, struct s_island* to) {
	fill_forward_pathes(from, to);

	t_pair *pair = mx_create_pair(from, to);
	char *route = mx_strdup(from->name);
    char *distance = mx_strdup("\0");
    mx_output(pair, from, route, distance);
    mx_free_pair(pair);
}
