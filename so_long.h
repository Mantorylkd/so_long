#ifndef SO_LONG_H
# define SO_LONG_H

#define TILE_SIZE 64

#include "/usr/include/minilibx-linux/mlx.h"
#include <mlx.h>


typedef struct s_game {
    // Map data
    char    **map;
    int     map_height;
    int     map_width;
    
    // Player info
    int     player_x;
    int     player_y;
    int     collectibles;

    // MLX pointers
    void    *mlx;
    void    *win;

    // Textures (add these!)
    void    *wall_img;      // Texture for walls ('1')
    void    *player_img;    // Texture for player ('P')
    void    *collect_img;   // Texture for collectibles ('C')
    void    *exit_img;      // Texture for exit ('E')
    void    *floor_img;     // Texture for empty space ('0')
} t_game;


int     parse_map(char *file, t_game *game);
int     read_map(int fd, t_game *game);
int     validate_map(t_game *game);
int     closed_by_walls(char **map);
int     valid_cmpnts(t_list  **map);
int     error_hit(char *msg);
void    find_player(char **map, int *x, int *y);


#endif 