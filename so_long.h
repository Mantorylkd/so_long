#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_game {
    void    *mlx;       // Connection to MiniLibX graphics system
    void    *win;       // The game window
    char    **map;      // 2D array storing your map (0,1,C,E,P)
    int     moves;      // Counts how many moves the player made
} t_game;

#include "/usr/include/minilibx-linux/mlx.h";
#incude <mlx.h>

#endif 