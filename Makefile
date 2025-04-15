NAME = so_long

SRCS = main.c ft_printf.c  printf_functions1.c  printf_functions2.c  map_params.c ft_putstr_fd.c ft_move.c ft_memset.c get_next_line.c get_next_line_utils.c ft_putimage.c  parcing_map.c  test.c ft_split.c  valid_path.c ft_strnstr.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)  -L/usr/include/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lz

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : re all clean fclean