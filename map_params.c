#include "so_long.h"

int     closed_bwall_imgalls(char **map) 
{
    int i;
    int last_row;
    int last_col;
    
    last_row = 0;
    while(map[last_row])
        last_row++;
    last_col = ft_strlen(map[0]) - 1;
    i = 0;
    while (i < (int)ft_strlen(map[0])) 
    {
        if (map[0][i] != '1' || map[last_row - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < last_row) 
    {
        if (map[i][0] != '1' || map[i][last_col] != '1')
            return (0);
        i++;
    }
    return (1);
}


int     valid_cmpnts(t_game  *map)
{
    int p = 0;
    int c = 0;
    int e = 0;
    int y = 0;
    int x;

    while(map->map[y])
    {  
        x = 0;
        while (map->map[y][x])
        {
            if(map->map[y][x] == 'P')
                p++;
            else if(map->map[y][x] == 'E')
                e++;
            else if(map->map[y][x] == 'C')
                c++;
            else if(map->map[y][x] != '0' && map->map[y][x] != '1')
                ft_error(ft_free(map->map), "invaild map\n", -1);
            x++;
        }
        y++;
    }
    if (c < 1 || p != 1 || e != 1)
        {
            return 0;
        }
    return 1;
}
