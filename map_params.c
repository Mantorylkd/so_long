#include "so_long.h"


int is_rectangular(char **map)
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


int is_closed_by_walls(char **map) 
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

