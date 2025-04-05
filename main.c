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


void flood_fill(char **map, int x, int y, int height, int width) {
    t_queue *queue = NULL;

    enqueue(&queue, x, y);
    while (queue != NULL) {
        dequeue(&queue, &x, &y);
        
        // Skip if out of bounds, wall, or already visited
        if (x < 0 || y < 0 || x >= width || y >= height || 
            map[y][x] == '1' || map[y][x] == 'X')
            continue;

        // Mark as visited
        map[y][x] = 'X';

        // Enqueue adjacent tiles
        enqueue(&queue, x + 1, y);
        enqueue(&queue, x - 1, y);
        enqueue(&queue, x, y + 1);
        enqueue(&queue, x, y - 1);
    }
}


int has_valid_path(t_game *game) {
    char **visited;
    int p_x, p_y;
    int valid;

    // Create a visited map copy
    visited = copy_map(game->map);
    if (!visited)
        return (0);

    // Find player position
    find_player(visited, &p_x, &p_y);

    // Flood fill from player position
    flood_fill(visited, p_x, p_y, game->map_height, game->map_width);

    // Check if all collectibles and exit are reachable
    valid = check_reachable(visited, 'C') && check_reachable(visited, 'E');

    free_map(visited, game->map_height);
    return (valid);
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