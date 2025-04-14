#include "so_long.h"

void ft_error(char *str, char *mess, int fd)
{
    free(str);
    write(2, "ERROR\n", ft_strlen("ERROR\n"));
    ft_putstr_fd(mess, 2);
    if (fd > 0)
        close (fd);
    exit(1);
}

char *ft_readmap(int fd) 
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
            return (free(tmp), ft_error(tmp, "faild allocation", fd), NULL);
        cont = ft_strjoin(cont, tmp);
        if (!cont)
            return (free(tmp), ft_error(tmp, "faild allocation", fd), NULL);    
    }
    free(tmp);
    close(fd);
    return (cont);
}

int parse_map(t_game *game, int fd)
{
    char *str;

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

    return (1);
} 


int is_rectangular(char **map)
{
    int len;
    int i;

    i = 0;
    len = (int)ft_strlen(map[i++]);
    while (map[i])
    {
        if (len != (int)ft_strlen(map[i]))
            return (0);
        i++;
    }
    return (1);
}
void validate_map(t_game *game)
{
    if (!is_rectangular(game->map))
        ft_error(ft_free(game->map), "your map is not rectangular\n", -1); 
    if (!closed_bwall_imgalls(game->map))
       ft_error(ft_free(game->map), "your map is not surounded by 1\n", -1);
    if (!valid_cmpnts(game))
        ft_error(ft_free(game->map), "you need only 1 (E P) or more C\n", -1);
}
