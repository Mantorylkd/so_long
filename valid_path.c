#include "so_long.h"

int is_validmap(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '1' && map[i][j] != '0')
                return (ft_free(map), 0);
            j++;
        }
        i++;
    }
    return (1);
}

int has_valid_path(t_game *game) 
{
    char **visited = copy_map(game->map);

    if (!visited)
        return 0;
    int p_x, p_y;

    find_player(visited, &p_x, &p_y);
    game->player_x = p_y;
    game->player_y = p_x;


    flood_fill(visited, p_x, p_y);
    if (!is_validmap(visited))
        ft_error(ft_free(game->map), "invalaid map\n", -1);
    free_map(visited);

    return 1;
}

char **copy_map(char **map) 
{
    char **copy;
    int i = 0;

    while (map[i])
        i++;
    copy = malloc(sizeof(char *) * (i + 1));
    if (!copy) 
        return (NULL);
    i = 0;
    while (map[i])
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i]) 
        {
            free_map(copy);
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

void free_map(char **map) {
    int i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
}

void find_player(char **map, int *x, int *y) 
{
    *y = 0;
    while (map[*y]) 
    {
        *x = 0;
        while (map[*y][*x]) 
        {
            if (map[*y][*x] == 'P')
                return;  // Found player - exit with (x,y) set
            (*x)++;
        }
        (*y)++;
    }
}


void flood_fill(char **map, int x, int y) {
    

    if (map[y][x] == '1')
    {
        return;
    }

    map[y][x] = '1';

    flood_fill(map, x, y + 1);  // Right
    flood_fill(map, x, y - 1);  // Left
    flood_fill(map, x + 1, y);  // Down
    flood_fill(map, x - 1, y);  // Up
}