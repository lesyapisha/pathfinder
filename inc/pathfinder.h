// header file path.h

#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx/inc/libmx.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
    char *islandName1;
    char *islandName2;
    int length_of_bridge;
} t_bridge;

struct s_path;

struct s_island{
	char *name;
	struct s_path **paths;
	int path_count;
	int shortest_path;
	struct s_path **best_routes;
	int best_routes_count;
};

//описує шлях з одного острову до іншого
struct s_path{
	struct s_island *to;
	int length_of_bridge;
};

int mx_size_of_file(char **lines);
void mx_fill_islands(t_bridge** array_of_bridges, struct s_island** islands, int num_of_bridges);
t_bridge* mx_split_line(char *line);
struct s_island* mx_get_island(char *name, struct s_island ***islands, int num_of_bridges);
struct s_path* mx_create_path(struct s_island* island, int length_of_bridge);
void mx_algo(struct s_island** islands, int number_of_islands);
void mx_process_island(struct s_island* island, int count_of_islands);
void mx_output_result(struct s_island* from, struct s_island* to);
int mx_text_of_file(int argc, char *argv[], char ***lines);
int mx_fill_bridges(char **lines, t_bridge** array_of_bridges);

void mx_free_bridges(t_bridge** bridges, int num_of_bridges);
void mx_free_islands(struct s_island** islands, int number_of_islands);
void mx_free_paths(struct s_path** paths);

void test_path(struct s_island** islands);

// errors
int mx_err_valid_command_lines(int argc);
int mx_err_no_file(char* filename);
int mx_err_file_is_empty(char* text_of_file, char* filename);
int mx_err_1st_line_invalid(char* first_line);
int mx_err_invalid_lines(char* line, int index);
int mx_err_invalid_number_of_islands(struct s_island** islands, int number_of_islands);

#endif
