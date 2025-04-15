#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#include "printf.h"
# include <X11/keysym.h>
#include "/usr/include/minilibx-linux/mlx.h"
#include "/usr/include/minilibx-linux/mlx_int.h"


#define TILE_SIZE 64

typedef struct s_game {
    // Map game
    char    **map;
    int     map_height;
    int     map_TILE_SIZE;
    
    // Player info
    int     player_x;
    int     player_y;
    int     collectibles;

    // moves
    int     move;

    // position of exit
    int exit_y;
    int exit_x;

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
int     closed_bwall_imgalls(char **map);
int     valid_cmpnts(t_game  *map);
void    find_player(char **map, int *x, int *y);
int has_valid_path(t_game *game) ;
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_free(char **split);
// error functions

void error_exit(t_game *game, char *message) ;
int     error_hit(char *msg);
void	*ft_memset(void *s, int c, size_t n);
// map copie

char **copy_map(char **map);
// flood fill 

void flood_fill(char **map, int y, int x);

// mlx functions

void load_textures(t_game *game);
void init_graphics(t_game *game);
void free_map(char **);
void	ft_putstr_fd(char *s, int fd);
void render_map(t_game *game);
char	**ft_split(char const *s, char c);

void	ft_putxpm(t_game *game);
void	ft_putimage(t_game *game);
void succed_exit(t_game *game) ;

void ft_error(char *str, char *mess, int fd);

void go_down(t_game *game);
void go_up(t_game *game);
void go_left(t_game *game);
void go_right(t_game *game);

#endif 
