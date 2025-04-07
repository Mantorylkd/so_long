#include "so_long.h"

int has_valid_path(t_game *game) 
{
    char **visited = copy_map(game->map);
    if (!visited)
        return 0;

    int p_x, p_y;
    find_player(visited, &p_x, &p_y);

    flood_fill(visited, p_x, p_y, game->map_height, game->map_width);

    // int valid = check_reachable(visited, 'C') && check_reachable(visited, 'E');
    free_map(visited, game->map_height);
    return valid;
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
    i = 0;
    while (map[i++])
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i]) 
        {
            free_map(copy, i);
            return (NULL);
        }
    }
    copy[i] = NULL;
    return (copy);
}

void free_map(char **map, int height) {
    int i = 0;
    while (i++ < height)
        free(map[i]);
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
    *x = 0 ; *y = 0;  // Player not found (invalid map)
}


void flood_fill(char **map, int y, int x, int height, int width) {
    
    if (y < 0 || x < 0 || y >= height || x >= width || map[y][x] == '1')
        return;

    map[y][x] = '1';

    flood_fill(map, y, x + 1, height, width);  // Right
    flood_fill(map, y, x - 1, height, width);  // Left
    flood_fill(map, y + 1, x, height, width);  // Down
    flood_fill(map, y - 1, x, height, width);  // Up
}