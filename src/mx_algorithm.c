#include "../Libmx/src/libmx.h"

static void add_best_route(struct s_island* island, struct s_island* to_island, struct s_path* path){
	to_island->best_routes[to_island->best_routes_count] = mx_create_path(island, path->length_of_bridge);
	to_island->best_routes[to_island->best_routes_count + 1] = NULL;
	to_island->best_routes_count = to_island->best_routes_count + 1;
}

static void init_best_routes(struct s_island* island, struct s_island* to_island, struct s_path* path, int number_of_islands){
	to_island->shortest_path = island->shortest_path + path->length_of_bridge;
	to_island->best_routes = (struct s_path**) malloc(number_of_islands * sizeof(struct s_path*));
	to_island->best_routes_count = 0;
	add_best_route(island, to_island, path);
}

// метод, який заповнює поля структур типу Island даними про найкоротший шлях 
// та pointer на острів з якого прийшли в поточний
void mx_process_island(struct s_island* island, int number_of_islands){
	int i = 0;
	struct s_path* path = NULL;
	struct s_island* to_island = NULL;

	while (island->paths[i] != NULL){
		path = island->paths[i];
		to_island = path->to;

		if (island->shortest_path + path->length_of_bridge < to_island->shortest_path 
		    || to_island->shortest_path == -1){

			init_best_routes(island, to_island, path, number_of_islands);
			mx_process_island(to_island, number_of_islands);
		} else if (island->shortest_path + path->length_of_bridge == to_island->shortest_path) {
			add_best_route(island, to_island, path);
		}

		i++;
	}
}

// реалізація алгоритму, який рахує найкоротший шлях
// вивід результату в заданому форматі за умовою задачі
void mx_algo(struct s_island** islands, int number_of_islands){
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i < number_of_islands; i++){
		k = 0;
		while (islands[k] != NULL){
			islands[k]->shortest_path = -1;
			islands[k]->best_routes = (struct s_path**) malloc(number_of_islands * sizeof(struct s_path*));
    		islands[k]->best_routes_count = 0;
    		islands[k]->best_routes[0] = NULL;
			k++;
		}
		islands[i]->shortest_path = 0; 
		mx_process_island(islands[i], number_of_islands);
		for (j = i + 1; j < number_of_islands; j++){
			mx_output_result(islands[i], islands[j]);
		}
	}
}
