#ifndef SO_LONG_H
# define SO_LONG_H

#include "/usr/include/minilibx-linux/mlx.h"
#include <mlx.h>


typedef struct s_game {
    char    **map;
    int     map_height;
    int     map_width;
    int     player_x;
    int     player_y;
    int     collectibles;
    void    *mlx;
    void    *win;
} t_game;


int     parse_map(char *file, t_game *game);
int     read_map(int fd, t_game *game);
int     validate_map(t_game *game);
int     closed_by_walls(char **map);
int     valid_cmpnts(t_list  **map);
int     error_hit(char *msg);
void    find_player(char **map, int *x, int *y);


#endif 