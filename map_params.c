#include "so_long.h"


int     is_rectangular(char **map)
{
    int i = 1;
    int first_line = strlen(map[0]);

    while(map[i])
    {
        if(strlen(map[i]) != first_line )
            return 0;
        i++
    }
    return 1;
} 


int     closed_by_walls(char **map) 
{
    int i;
    int last_row;
    int last_col;
    
    last_row = 0;
    while(map[last_row])
        last_row++;
    last_col = ft_strlen(map[0]) - 1;
    
    i = 0;
    while (i < ft_strlen(map[0])) {
        if (map[0][i] != '1' || map[last_row - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < last_row) {
        if (map[i][0] != '1' || map[i][last_col] != '1')
            return (0);
        i++;
    }
    return (1);
}


int     valid_cmpnts(t_list  **map)
{
    int p = 0;
    int c = 0;
    int e = 0;
    int y = 0;
    int x = 0;

    while(map[y])
    {   
        while (map[y][x])
        {
            if(map[y][x] == 'P')
                p++;
            else if(map[y][x] == 'E')
                e++;
            else if(map[y][x] == 'C')
                c++;
            else if(map[y][x] != '0' && map[y][x] != '1')
                write(2,"invalid characters",18);
            x++;
        }
        y++;
    }
    if (c < 1 || p != 1 || e != 1)
        {
            write(2,"invalid number of characters",28);
            return 0;
        }
    return 1;
}
