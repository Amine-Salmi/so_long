NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBMLX = ~/MLX42

HEADERS = -I ./include -I $(LIBMLX)/include/MLX42
LIBS    = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# LIBS = ../../MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/asalmi/.brew/opt/glfw/lib"
RM = rm -rf

SRC = exit.c load_images.c main.c move.c parsing_utils.c parsing.c path_finding.c \
		print_map.c set_map.c utils_function.c utils2_function.c ./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

OBJC = $(SRC:.c=.o)

RED=\033[0;31m
PURPLE=\033[0;35m
NC=\033[0m

all : libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME) : $(OBJC) so_long.h
	@$(CC) $(CFLAGS) $(OBJC) $(LIBS) -o $@
	@echo "${PURPLE}MANDATORY DONE${NC}"

%.o : %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJC)
	@rm -rf $(LIBMLX)/build

fclean : clean
	@$(RM) $(NAME)
	@echo "${RED}CLEANING MANDATORY...${NC}"

re : fclean all

.PHONY : clean 