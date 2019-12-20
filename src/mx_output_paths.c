#include "../Libmx/src/libmx.h"

static char* output_path(struct s_island* from, struct s_island* to){
	char* path_str;

	path_str = mx_strjoin("Path: ", from->name);
	path_str = mx_strjoin(path_str, " -> ");
	path_str = mx_strjoin(path_str, to->name);
	path_str = mx_strjoin(path_str, "\n");

	return path_str;
}

static void print(char* path, char* route, char* distance) {
	char* result_str;

	route = mx_strjoin("Route: ", route);
	route = mx_strjoin(route, "\n");

	distance = mx_strjoin("Distance: ", distance);

	result_str = mx_strjoin("========================================\n", path);
	result_str = mx_strjoin(result_str, route);
	result_str = mx_strjoin(result_str, distance);
	result_str = mx_strjoin(result_str, "\n========================================\n");
	mx_printstr(result_str);
}

static char* create_distance_str(char* old_distance_str, struct s_path* route, 
								struct s_island* from, struct s_island* to, int shortest_path){
	char* new_distance_str;

	if (mx_strcmp(from->name, route->to->name) == 0) {
		if (old_distance_str == NULL){
			new_distance_str = mx_itoa(to->shortest_path);
		} else {
			new_distance_str = mx_strjoin(mx_itoa(route->length_of_bridge), old_distance_str);
			new_distance_str = mx_strjoin(new_distance_str, " = ");
			new_distance_str = mx_strjoin(new_distance_str, mx_itoa(shortest_path));
		}
	} else {
		new_distance_str = mx_strjoin(mx_itoa(route->length_of_bridge), old_distance_str);
		new_distance_str = mx_strjoin(" + ", new_distance_str);
	}
	return new_distance_str;
}

static void fill_route_and_distance(struct s_island* from, struct s_island* to, char* path,
							 	    char* route, char* distance, int shortest_path) {
	int i = 0;
	char* distance_str;
	char* route_str;

	if(mx_strcmp(to->name, from->name) == 0){
		print(path, route, distance);
		return;
	}
	while(to->best_routes[i] != NULL) {
		route_str = mx_strjoin(" -> ", route);
		route_str = mx_strjoin(to->best_routes[i]->to->name, route_str);
		distance_str = create_distance_str(distance, to->best_routes[i], from, to, shortest_path);
		fill_route_and_distance(from, to->best_routes[i]->to, path, route_str, distance_str, shortest_path);
		i++;
	}
}

void mx_output_result(struct s_island* from, struct s_island* to){
	char *path = output_path(from, to);
	char *route = to->name;
	char *distance = NULL;

	fill_route_and_distance(from, to, path, route, distance, to->shortest_path);
}
