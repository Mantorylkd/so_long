#include "so_long.h"


int key_move(int key, void *ptr)
{
    t_game	*game;

	game = (t_game *)ptr;
    if (key == XK_Escape)
        succed_exit(game);
    if (key == XK_Up)
        go_up(game);
    if (key == XK_Down)
        go_down(game);
    if (key == XK_Left)
        go_left(game);
    if (key == XK_Right)
        go_right(game);
    ft_putimage(game);
    return (0);
}

int exit_game(void *ptr)
{
    t_game	*game;

	game = (t_game *)ptr;
	succed_exit(game);
    return (0);
}

int ft_len(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

// void ft_str(char **str)
// {
//     int i;

//     i = 0;
//     printf("%s\n", str[i++]);
//     //while(str[i])
//     printf("hello\n");
// }

void init_graphics(t_game *game) 
{

    game->mlx = mlx_init();


    if (!game->mlx)
        error_exit(game, "MLX initialization failed");

    //ft_str(game->map);
    game->win = mlx_new_window(game->mlx,
                              ft_strlen(game->map[0]) * TILE_SIZE,
                              ft_len(game->map) * TILE_SIZE,
                              "so_long");

    if (!game->win)
        error_exit(game, "Window creation failed");

    ft_putxpm(game);
    ft_putimage(game);

    mlx_hook(game->win, 2, 1L << 0, key_move, game);
	mlx_hook(game->win, 17, 0, exit_game, game);

    mlx_loop(game->mlx);
}

void error_exit(t_game *game, char *message) 
{
    // Print error message to stderr
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(message, 2);
    ft_putstr_fd("\n", 2);
    
    // Clean up resources if they exist
    if (game->mlx) 
    {
        if (game->win) mlx_clear_window(game->mlx, game->win);
        if (game->win) mlx_destroy_window(game->mlx, game->win);
        free(game->mlx);
    }
    ft_free(game->map);
    exit(EXIT_FAILURE);
}


void succed_exit(t_game *game) 
{

	if (game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	ft_free(game->map);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
	free(game->mlx);
    //ft_free(game->map);
    exit(0);
}