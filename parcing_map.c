#include "so_long.h"

void ft_error(char *str, char *mess, int fd)
{
    free(str);
    write(2, "ERROR\n", ft_strlen("ERROR\n"));
    ft_putstr_fd(mess, fd);
    if (fd < 0)
        close (fd);
    exit(1);
}

int ft_readmap(int fd) 
{
    char    *cont;
    char    *tmp;
    int     i;

    tmp = ft_strdup(" ");
    if (!tmp)
        ft_error(NULL, "faild allocation", fd);
    cont = ft_strdup("");
    if (!cont)
        ft_error(tmp, "faild allocation", fd);
    while (1)
    {
        i = read(fd, tmp, 1);
        if (i == 0)
            break ;
        if (i < 0)
            return (free(tmp), ft_error(tmp, "faild allocation", fd), 0);
        cont = ft_strjoin(cont, tmp);
        if (!cont)
            return (free(tmp), ft_error(tmp, "faild allocation", fd), 0);    
    }
    free(tmp);
    close(fd);
    return (cont);
}

int parse_map(t_game *game, int fd)
{
    char *str;
    char **map;

    str = ft_readmap(fd);
    if (ft_strnstr(str, "\n\n", ft_strlen(str)))
        ft_error(str, "a new line in your map \n", -1);
    game->map = ft_split(str, '\n');
    free(str);
    if (!(game->map))
        error_hit("faild allocation \n");
    validate_map(game);
    if (!has_valid_path(game))
        ft_error(ft_free(game->map), "invalid map\n", -1);
} 


void validate_map(t_game *game)
{
    if(!closed_by_walls(game->map))
        error_hit("your map doesnt surround with walls");
    if(!valid_cmpnts(game))
        error_hit("you need 0 1 P C E");
}
