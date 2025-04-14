#include "so_long.h"


int ft_collect(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_exit_hanle(t_game *game, int newx, int newy)
{
    if (game->exit_x == game->player_x && game->exit_y == game->player_y)
    {
        if (!ft_collect(game->map))
        {
            succed_exit(game);
        }
            
        game->map[game->exit_x][game->exit_y] = 'E';
        game->map[newx][newy] = '0';
        game->player_x = newx;
        game->player_y = newy;
        game->exit_x = 0;
        game->exit_y = 0;
        return (1);
    }
    else if (game->map[game->player_x - 1][game->player_y] == 'E')
    {
        game->exit_x = newx;
        game->exit_y = newy;
        game->map[newx][newy] = 'P';
        game->map[game->player_x][game->player_y] = '0';
        game->player_x = newx;
        game->player_y = newy;
        return (1);
    }
    return (0);
}

void go_up(t_game *game)
{
    int newx;
    int newy;

    if (game->map[game->player_x - 1][game->player_y] == '1')
        return ;
    if (ft_exit_hanle(game, game->player_x - 1, game->player_y))
        return ;
    else
    {
        newx = game->player_x - 1;
        newy = game->player_y;
        game->map[game->player_x ][game->player_y] = '0';
        game->map[newx][newy] = 'P';
        game->player_x = newx;
        game->player_y = newy;
    }
}


void go_down(t_game *game)
{
    int newx;
    int newy;

    if (game->map[game->player_x + 1][game->player_y] == '1')
        return ;
    if (ft_exit_hanle(game, game->player_x + 1, game->player_y))
        return ;
    else
    {
        newx = game->player_x + 1;
        newy = game->player_y;
        game->map[game->player_x][game->player_y] = '0';
        game->map[newx][newy] = 'P';
        game->player_x = newx;
        game->player_y = newy;
    }
}

void go_left(t_game *game)
{
    int newx;
    int newy;

    if (game->map[game->player_x][game->player_y - 1] == '1')
        return ;
    if (ft_exit_hanle(game, game->player_x , game->player_y - 1))
        return ;
    else
    {
        newx = game->player_x;
        newy = game->player_y - 1;
        game->map[game->player_x][game->player_y] = '0';
        game->map[newx][newy] = 'P';
        game->player_x = newx;
        game->player_y = newy;
    }
}

void go_right(t_game *game)
{
    int newx;
    int newy;

    if (game->map[game->player_x][game->player_y + 1] == '1')
        return ;
    if (ft_exit_hanle(game, game->player_x, game->player_y + 1))
        return ;
    else
    {
        newx = game->player_x;
        newy = game->player_y + 1;
        game->map[game->player_x][game->player_y] = '0';
        game->map[newx][newy] = 'P';
        game->player_x = newx;
        game->player_y = newy;
    }
}