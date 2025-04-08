#include "so_long.h"


int main(int argc, char **argv) 
{
    t_game game;

    if (argc != 2)
        error_hit()
    if(!parse_map(argv[1], &game))
        return (1);

    if (!has_valid_path(&game)) 
    {
        free_map(game.map, game.map_height);
        return (error("No valid path to collectibles/exit"));
    }

    init_graphics(&game);
    game_loop(&game);
    free_resources(&game);
    return (0);
}


int error_hit(char *msg) 
{
        write(2,"Error",5);
        return (0);
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