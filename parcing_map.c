#include "so_long.h"

int parse_map(char *file, t_game *game) 
{
    int fd = open(file, O_RDONLY);
    if (fd == -1)
        return (error("Failed to open map"), 0);
    
    char *line;
    game->map_height = 0;
    game->map_width = -1; 
    
    while ((line = get_next_line(fd))) 
    {
        int line_len = (int)ft_strlen(line);
        if (line[line_len - 1] == '\n')
            line_len--; 
        
        if (game->map_width == -1) 
            game->map_width = line_len;
        else if (line_len != game->map_width) 
        {
            free(line);
            close(fd);
            return (error("Map is not rectangular"), 0);
        }
        game->map_height++;
        free(line);
    }
    close(fd);
    fd = open(file, O_RDONLY);
    if (!read_map(fd, game))
    {
        close(fd);
        return (0);
    }
    close(fd);
    return (1);
}

int read_map(int fd, t_game *game) 
{
    char    *line;
    char    *temp_map = NULL;
    char    *temp_line;
    
    while (1) {
        line = get_next_line(fd);
        if (!line)
            break;
        temp_line = ft_strjoin(temp_map, line);
        free(temp_map);
        free(line);
        temp_map = temp_line;
    }
    game->map = ft_split(temp_line, '\n');
    free(temp_map);
    return (game->map != NULL);
}



int validate_map(t_game *game)
{
    if(!is_valid_cmpnts(game->map))
        error_hit();
    if(!closed_by_walls(game->map))
        error_hit();
}


