/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhallaf <ekhallaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:27:08 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/14 23:10:49 by ekhallaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error_d(t_game *game)
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
	free(game->mlx);
}

void	ft_putxpm(t_game *game)
{
	int	i;
	int	j;

	game->collect_img = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm", &i, &j);
	if (!game->collect_img)
		ft_error_d(game);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&i, &j);
	if (!game->exit_img)
		ft_error_d(game);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &i, &j);
	if (!game->player_img)
		ft_error_d(game);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &i, &j);
	if (!game->wall_img)
		ft_error_d(game);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &i,
			&j);
	if (!game->floor_img)
		ft_error_d(game);
}

void	ft_putimage(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img,
					TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
					TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
					TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img,
					TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
					TILE_SIZE * j, TILE_SIZE * i);
			j++;
		}
		i++;
	}
}
