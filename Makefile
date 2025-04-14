NAME = so_long

SRCS = main.c  map_params.c ft_putstr_fd.c get_next_line.c get_next_line_utils.c  parcing_map.c  test.c ft_split.c  valid_path.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)  -L/usr/include/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lz

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : re all clean fclean