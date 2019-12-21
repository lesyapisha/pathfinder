// header file libmx.h

#ifndef LIBMX_H
#define LIBMX_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_list {
	void *data;
	struct s_list *next;
}	t_list;

// pathfinder

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

//Utils pack

void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_itoa(int number);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);

//String pack

int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_file_to_str(const char *file);
int mx_read_line(char **lineptr, int buf_size, char delim, const int fd);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);

//Memory pack

void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);

// List pack

t_list  *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));

//non-library functions

bool mx_isspace(char c);
bool mx_isdigit(int c);
bool mx_isalpha(int c);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strchr(const char *s, int c);
void mx_strdel(char **str);
int mx_atoi(const char *str);
int mx_size_arr(char** arr);

// path
int mx_size_of_file(char **lines);
void mx_fill_islands(t_bridge** array_of_bridges, struct s_island** islands, int num_of_bridges);
t_bridge* mx_split_line(char *line);
struct s_island* mx_get_island(char *name, struct s_island **islands, int num_of_bridges);
struct s_path* mx_create_path(struct s_island* island, int length_of_bridge);
void mx_algo(struct s_island** islands, int number_of_islands);
void mx_process_island(struct s_island* island, int count_of_islands);
void mx_output_result(struct s_island* from, struct s_island* to);
int mx_text_of_file(int argc, char *argv[], char ***lines);
int mx_fill_bridges(char **lines, t_bridge** array_of_bridges);

void mx_free_bridges(t_bridge** bridges);
void mx_free_islands(struct s_island** islands);
void mx_free_paths(struct s_path** paths);

void test_path(struct s_island** islands);

// errors
int mx_err_valid_command_lines(int argc);
int mx_err_no_file(char* filename);
int mx_err_file_is_empty(char* text_of_file, char* filename);
int mx_err_1st_line_invalid(char* first_line);
void mx_err_invalid_lines(int index);
int mx_err_invalid_number_of_islands(struct s_island** islands, int number_of_islands);

#endif
