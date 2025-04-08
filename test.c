#include "so_long.h"

void init_graphics(t_game *game) 
{
    game->mlx = mlx_init();
    if (!game->mlx)
        error_exit(game, "MLX initialization failed");

    game->win = mlx_new_window(game->mlx,
                              game->map_width * TILE_SIZE,
                              game->map_height * TILE_SIZE,
                              "so_long");
    if (!game->win)
        error_exit(game, "Window creation failed");

    load_textures(game);

    render_map(game);
}


void load_textures(t_game *game) 
{
    int img_width, img_height;

    game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &img_width, &img_height);
    
    game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &img_width, &img_height);
    
    game->collect_img = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm", &img_width, &img_height);
    
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &img_width, &img_height);
    
    game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &img_width, &img_height);

    if (!game->wall_img || !game->player_img || !game->collect_img || 
        !game->exit_img || !game->floor_img) {
        error_exit(game, "Failed to load textures");
    }
}


void render_map(t_game *game)
{
    int x = 0;
    int y = 0;
    void *img;

    mlx_clear_window(game->mlx, game->win);

    while (y < game->map_height)
    {
        x = 0;
        
        while (x < game->map_width)
        {
            if (game->map[y][x] == '1')
                img = game->wall_img;
            else if (game->map[y][x] == 'P')
                img = game->player_img;
            else if (game->map[y][x] == 'C')
                img = game->collect_img;
            else if (game->map[y][x] == 'E')
                img = game->exit_img;
            else
                img = game->floor_img;

            mlx_put_image_to_window(game->mlx,game->win,img, x * TILE_SIZE, y * TILE_SIZE);
            x++; 
        }
        y++;
    }
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
        if (game->wall_img) mlx_destroy_image(game->mlx, game->wall_img);
        if (game->player_img) mlx_destroy_image(game->mlx, game->player_img);
        if (game->collect_img) mlx_destroy_image(game->mlx, game->collect_img);
        if (game->exit_img) mlx_destroy_image(game->mlx, game->exit_img);
        if (game->floor_img) mlx_destroy_image(game->mlx, game->floor_img);
        if (game->win) mlx_destroy_window(game->mlx, game->win);
        // Note: Don't destroy mlx itself as it may cause issues on some systems
    }

    exit(EXIT_FAILURE);
}


