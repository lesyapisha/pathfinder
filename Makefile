APP_NAME = pathfinder

LIBMXF = libmx

LIB_NAME = libmx.a

INC = pathfinder.h

INCF = inc/pathfinder.h

SRC = \
main.c \
mx_error_handler.c \
mx_error_handler_2.c \
mx_algorithm.c \
mx_bridge_factory.c \
mx_island_factory.c \
mx_path_factory.c \
mx_output_paths.c \
mx_size_of_file.c \
mx_split_line.c \
mx_split_line_2.c \
mx_text_of_file.c \
mx_pair_factory.c \
mx_printerr.c \
mx_create_distance_str.c \
# mx_correct_count_words.c \
# mx_correct_strsplit.c \

SRCF = \
src/main.c \
src/mx_error_handler.c \
src/mx_error_handler_2.c \
src/mx_algorithm.c \
src/mx_bridge_factory.c \
src/mx_island_factory.c \
src/mx_path_factory.c \
src/mx_output_paths.c \
src/mx_size_of_file.c \
src/mx_split_line.c \
src/mx_split_line_2.c \
src/mx_text_of_file.c \
src/mx_pair_factory.c \
src/mx_printerr.c \
src/mx_create_distance_str.c \
# src/mx_correct_count_words.c \
# src/mx_correct_strsplit.c \

OBJ = \
main.o \
mx_error_handler.o \
mx_error_handler_2.o \
mx_algorithm.o \
mx_bridge_factory.o \
mx_island_factory.o \
mx_path_factory.o \
mx_output_paths.o \
mx_size_of_file.o \
mx_split_line.o \
mx_split_line_2.o \
mx_text_of_file.o \
mx_pair_factory.o \
mx_printerr.o \
mx_create_distance_str.o \
# mx_correct_count_words.o \
# mx_correct_strsplit.o \


CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C $(LIBMXF)
	@cp $(SRCF) .
	@cp $(INCF) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) $(OBJ) $(LIBMXF)/$(LIB_NAME) -o $(APP_NAME)
	@mkdir -p ./obj
	@mv $(OBJ) ./obj

uninstall:
	@make uninstall -C $(LIBMXF)
	@rm -rf $(APP_NAME)

clean:
	@make clean -C $(LIBMXF)
	@rm -rf $(INC)
	@rm -rf $(SRC)
	@rm -rf ./obj
	@rm -rf pathfinder.h.gch

reinstall: uninstall all
