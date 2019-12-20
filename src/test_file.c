#include "../Libmx/src/libmx.h"

void test_path(struct s_island** islands){
    //перевірка на коректність заповнення полів структур типу Island 
    //вивід всіх Island->name і їх paths
    for (int i = 0; islands[i] != NULL; i++) {
    	printf("islands[%d]: %s\n", i, islands[i]->name);
    	printf("paths:\n");
    	for (int j = 0; islands[i]->paths[j] != NULL; j++) {	
    		printf("%s, %d\n", islands[i]->paths[j]->to->name, islands[i]->paths[j]->length_of_bridge);
    	}
    	printf("Shortest path: %d\n", islands[i]->shortest_path);
    	// printf("Route length: %d\n", islands[i]->route_length);
    	// if(islands[i]->from != NULL){
    	// 	printf("From: %s\n", islands[i]->from->name);
    	// }
        printf("best routes:\n");
        for (int j = 0; islands[i]->best_routes[j] != NULL; j++) {    
            printf("%s, %d\n", islands[i]->best_routes[j]->to->name, islands[i]->best_routes[j]->length_of_bridge);
        }
    }
}
