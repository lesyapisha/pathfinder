#include "pathfinder.h"


static char* output_path(t_pair *pair) {
    char* path_str;

    path_str = mx_ms_strjoin(mx_strdup("Path: "),
               mx_strdup(pair->first->name));
    path_str = mx_ms_strjoin(path_str, mx_strdup(" -> "));
    path_str = mx_ms_strjoin(path_str, mx_strdup(pair->second->name));
    path_str = mx_ms_strjoin(path_str, mx_strdup("\n"));
    return path_str;
}

static void print(char *path, char *route, char *distance) {
    char *result_str;

    route = mx_ms_strjoin(mx_strdup("Route: "), route);
    route = mx_ms_strjoin(route, mx_strdup("\n"));
    distance = mx_ms_strjoin(mx_strdup("Distance: "), distance);
    result_str = mx_ms_strjoin(
    mx_strdup("========================================\n"), path);
    result_str = mx_ms_strjoin(result_str, route);
    result_str = mx_ms_strjoin(result_str, distance);
    result_str = mx_ms_strjoin(result_str, 
    mx_strdup("\n========================================\n"));
    mx_printstr(result_str);
    free(result_str);
}

static char *get_route_str(char *route, char* name) {
    char *r_str;

    r_str = mx_strjoin(" -> ", route);
    r_str = mx_ms_strjoin(mx_strdup(name), r_str);

    return r_str;
}

static void output(t_pair *pair, struct s_island *isl,
                   char *route, char *dist) {
    int i = 0;
    char *d_str;
    char *r_str;
    if(mx_strcmp(isl->name, pair->first->name) == 0) {
        print(output_path(pair), route, dist);
        return;
    }
    for (i = 0; isl->b_routes[i] != NULL; i++) {
        r_str = get_route_str(route, isl->b_routes[i]->to->name);
        d_str = mx_cr_dist_str(pair, isl->b_routes[i], mx_strdup(dist), isl);
        output(pair, isl->b_routes[i]->to, mx_strdup(r_str),
               mx_strdup(d_str));
        free(r_str);
        free(d_str);
    }
    free(route);
    free(dist);
}

char* mx_ms_strjoin(char* str1, char* str2) {
    char* result = mx_strjoin(str1, str2);

    if (str1 != NULL) {
        free(str1);
    }
    if (str2 != NULL) {
        free(str2);
    }
    return result;
}

void mx_output_result(struct s_island* from, struct s_island* to){
    t_pair *pair = mx_create_pair(from, to);
    char *route = mx_strdup(to->name);
    char *distance = mx_strdup("\0");

    output(pair, to, route, distance);
    mx_free_pair(pair);
}
