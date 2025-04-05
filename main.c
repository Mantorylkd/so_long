#include "so_long.h"


int main(int argc, char **argv) 
{
    if (argc != 2)
    return (ft_printf("Error: Usage: ./so_long <map.ber>\n"), 1);
    
    if (!parse_map(argv[1], &game))
    return (1); // Map parsing failed
    
    // init_game(&game);
    // mlx_loop(game.mlx);
    // return (0);
}










// int main()
// {
//     void    *mlx;
//     void    *mlx_win;

//     mlx = mlx_init();
//     mlx = mlx_new_window(mlx,1980,1500,"hi");
//     mlx_loop(mlx);
// }


// t_game game;