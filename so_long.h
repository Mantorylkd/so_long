#ifndef SO_LONG_H
# define SO_LONG_H

#include "/usr/include/minilibx-linux/mlx.h"
#include <mlx.h>

typedef struct s_game {
    void    *mlx;       // Connection to MiniLibX graphics system
    void    *win;       // The game window
    char    **map;      // 2D array storing your map (0,1,C,E,P)
    int     moves;      // Counts how many moves the player made
} t_game;


int parse_map(char *file, t_game *game);
int read_map(int fd, t_game *game);
int validate_map(t_game *game);
int     is_rectangular(char **map);
int     closed_by_walls(char **map);
int     valid_cmpnts(t_list  **map);



#endif 