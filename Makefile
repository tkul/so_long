NAME = so_long
CC = gcc

SRCS = error.c helpers.c helpers_2.c main.c map_border_check.c map_check.c map_objective_check.c window.c map_flood_fill_check.c free.c move.c inputs.c

MINILIBX = ./mlx/libmlx.a

LIBFT_PATH=libft
LIBFT=$(LIBFT_PATH)/libft.a

CFLAGS=-Wall -Wextra -Werror -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft -I ./mlx -L ./mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS)
	@make -C ./mlx
	@make -C ./$(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MINILIBX) -o $(NAME)
	@echo "Executable created!"

clean:
	@make clean -C ./mlx
	@make clean -C ./libft
	@rm -f $(OBJ)
	@echo "Object files removed!"

fclean: clean
	@make clean -C ./mlx
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "Executable removed!"

re: fclean all

.PHONY: all clean fclean re bonus