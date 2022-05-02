/*
** YNOV PROJECT 2022
** by: arthur.viard@ynov.com
** File description :
** main statement
*/

#include "../include/astar.h"

void my_putsterror(char *str)
{
    int	i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
}

static void free_map(map_t *map)
{
    int i = 0;

    while (i != map->hauteur - 1) {
        free(map->map[i]);
        ++i;
    }
}

int main(int ac, char **av)
{
    origin_t *node = NULL;
    map_t *map = NULL;
    int rt = 0;

    if (ac != 2)
        return (1);
    map = malloc(sizeof(map_t));
    if (map_recuperation(map, av[1]) == 1)
        return (1);
    if ((node = init_origin(map)) == NULL)
        return (1);
    if ((rt = astar(map, node)) == 1)
        return (-1);
    else if (rt >= 0)
        map_printer(map, rt);
    free_map(map);
    free(node);
    return (0);
}
