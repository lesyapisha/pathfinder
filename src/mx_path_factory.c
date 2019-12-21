#include "../Libmx/src/libmx.h"

//метод, що створює і заповнює структуру типу Path
struct s_path* mx_create_path(struct s_island* island, int length_of_bridge){
	struct s_path* path = (struct s_path*) malloc(sizeof(struct s_path));
	
	// path->to = (struct s_island*) malloc(sizeof(struct s_island));
	path->to = island;
	path->length_of_bridge = length_of_bridge;

	return path;
}

void mx_free_paths(struct s_path** paths) {
	int index = 0;

	while (paths[index]) {
		free(paths[index]);
		index++;
	}

	free(paths);
}
