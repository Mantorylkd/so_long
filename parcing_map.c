#include "so_long.h"

int parse_map(char *file, t_game *game) 
{
    int fd = open(file, O_RDONLY);
    if (fd == -1)
        return (error("Failed to open map"), 0);
    
    if (!read_map(fd, game) || !validate_map(game)) {
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
    if(!is_rectangular(game->map))
    {
        write(2,"Map is not rectangular",22);
        return 0;
    }
    if(!is_valid_cmpnts(game->map))
    {
         write(2,"Map is not rectangular",22);
        return 0;
    }
    if(!)

}



