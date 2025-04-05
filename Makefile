NAME = so_long
SRCS = srcs/main.c srcs/map_parser.c srcs/game.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -Lminilibx -lmlx -lXext -lX11 -o $(NAME)

clean:
    rm -f $(OBJS)

fclean: clean
    rm -f $(NAME)

re: fclean all