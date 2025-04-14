#ifndef SO_LONG_H
# define SO_LONG_H

#define TILE_SIZE 64
#include "get_next_line.h"
#include "/usr/include/minilibx-linux/mlx.h"
#include "/usr/include/minilibx-linux/mlx_int.h"
//#include <mlx.h>


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


int     parse_map(t_game *game, int fd);
int     read_map(int fd, t_game *game);
void     validate_map(t_game *game);
int     closed_by_walls(char **map);
int     valid_cmpnts(t_game  *map);
void    find_player(char **map, int *x, int *y);
int has_valid_path(t_game *game) ;
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_free(char **split);
// error functions

void error_exit(t_game *game, char *message) ;
int     error_hit(char *msg);

// map copie

char **copy_map(char **map);
// flood fill 

void flood_fill(char **map, int y, int x, int height, int width);

// mlx functions

void load_textures(t_game *game);
void init_graphics(t_game *game);
void free_map(char **map, int height);
void	ft_putstr_fd(char *s, int fd);
void render_map(t_game *game);
char	**ft_split(char const *s, char c);

void ft_error(char *str, char *mess, int fd);

#endif 
