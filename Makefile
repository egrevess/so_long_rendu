NAME = so_long

SRCS = srcs/check_map.c srcs/f_strlen.c srcs/get_next_line_utils.c srcs/get_next_line.c \
	srcs/main.c srcs/map.c srcs/move.c srcs/put_in_tab_utils.c \
	srcs/image.c srcs/utils.c srcs/check_path.c \
	srcs/ft_printf.c srcs/ft_putchar.c srcs/ft_putnbr.c srcs/check_exit.c

OBJECT = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

# Minilibx 
MLX_DIR 	= mlx
MLX_PATH 	= ${MLX_DIR}/libmlx.a
MLX 		= -framework OpenGL -framework AppKit ${MLX_PATH}

$(NAME): $(OBJECT)
		@make -C ${MLX_DIR}
		$(CC) $(CFLAGS) -o $(NAME) $(OBJECT) $(MLX)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
		@make clean -C ${MLX_DIR}
		rm -f $(OBJECT)

fclean: clean
		rm -f $(NAME)

re: 	fclean $(NAME)

.PHONY: all clean fclean re 