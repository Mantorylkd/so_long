#include "so_long.h"


int main(int argc, char **argv) 
{
    if (argc != 2)
    return (ft_printf("Error: Usage: ./so_long <map.ber>\n"), 1);
    
    if (!parse_map(argv[1], &game))
    return (1);
    
    init_game(&game);
    mlx_loop(game.mlx);
    return (0);
}



int validate_map(t_game *game) {
    if (!is_rectangular(game->map))
        return (error("Map is not rectangular"), 0);
    if (!is_closed_by_walls(game->map))
        return (error("Map not surrounded by walls"), 0);
    if (!has_valid_components(game->map))
        return (error("Invalid map components"), 0);
    if (!has_valid_valid_path(game))
        return (error("No valid path to exit/collectibles"), 0);
    return (1);
}



int has_valid_path(t_game *game) 
{
    char **visited = copy_map(game->map);
    if (!visited)
        return 0;

    int p_x, p_y;
    find_player(visited, &p_x, &p_y);

    flood_fill(visited, p_x, p_y, game->map_height, game->map_width);

    int valid = check_reachable(visited, 'C') && check_reachable(visited, 'E');

    free_map(visited, game->map_height);
    return valid;
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
