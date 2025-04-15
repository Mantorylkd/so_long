#include "so_long.h"

int error_hit(char *msg) 
{
    write(2,"Error\n", ft_strlen("Error\n"));
    ft_putstr_fd(msg, 2);
    exit (1);
}

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
        error_hit("no name or no extension\n");
    if (ft_strcmp(str + len, ".ber"))
    // map.ber
        error_hit("no extension\n");
    len = open(str, O_RDONLY);
    if (len < 0)
        error_hit("no permission or no such a file");
    return (len);
}

int main(int argc, char **argv) 
{
    t_game game;

    ft_memset(&game, 0, sizeof(t_game));
    if (argc != 2)
        error_hit("./so_long <mapename>.ber");
    if(!parse_map(&game,  ft_is_valid(argv[1])))
        return (1);
    init_graphics(&game);
    return (0);
}

