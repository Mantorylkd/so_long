#include "so_long.h"

int error_hit(char *msg) 
{
    write(2,"Error\n",ft_strlen("Error\n"));
    write(2, msg, ft_strlen(msg));
    exit (1);
}


// int has_valid_path(t_game *game) 
// {
//     char **visited = copy_map(game->map);
//     if (!visited)
//         return 0;

//     int p_x, p_y;
//     find_player(visited, &p_x, &p_y);

//     flood_fill(visited, p_x, p_y, game->map_height, game->map_width);

//     //int valid = check_reachable(visited, 'C') && check_reachable(visited, 'E');

//     free_map(visited, game->map_height);
//     return 1;
// }


// void flood_fill(char **map, int y, int x, int height, int width) {
    
//     if (y < 0 || x < 0 || y >= height || x >= width || map[y][x] == '1')
//         return;

//     map[y][x] = '1';

//     flood_fill(map, y, x + 1, height, width);  // Right
//     flood_fill(map, y, x - 1, height, width);  // Left
//     flood_fill(map, y + 1, x, height, width);  // Down
//     flood_fill(map, y - 1, x, height, width);  // Up
// }


int ft_strcmp(char *s1, char *s2)
{
    while (*s1 || *s2)
    {
        if (*s1 != *s2)
            return (1);
        s1++;
        s2++;
    }
    return (0);
}

int ft_is_valid(char *str)
{
    int len;

    len = ft_strlen(str) - 4;
    if (len <= 0 || str[len - 1] == '/')
        error_hit("no name or no extention\n");
    if (ft_strcmp(str + len, ".ber"))
        error_hit("no extention\n");
    len = open(str, O_RDONLY);
    if (len < 0)
        error_hit("no permission or no such a file");
    return (len);
}

int main(int argc, char **argv) 
{
    t_game game;

    if (argc != 2)
        error_hit("./so_long <mapename>.ber");
    if(!parse_map(&game,  ft_is_valid(argv[1])))
        return (1);
    exit(1);
    printf("hello\n");
    if (!has_valid_path(&game)) 
    {
        free_map(game.map, game.map_height);
        return (error_hit("No valid path to collectibles/exit"));
    }
    printf("hello\n");
    init_graphics(&game);
    //game_loop(&game);
    //free_resources(&game);
    return (0);
}

