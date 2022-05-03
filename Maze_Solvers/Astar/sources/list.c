/*
** YNOV PROJECT 2022
** by: arthur.viard@ynov.com
** File description :
** list treatment
*/

#include <stdlib.h>
#include "../include/astar.h"

int add_neighbor_in_open(origin_t *node, open_t *neighbor)
{
    if (node != NULL) {
        neighbor->next = node->origin;
        node->origin = neighbor;
        return (0);
    }
    return (1);
}

int count_cells(origin_t *node)
{
    int nb_cells = 0;
    open_t *tmp;

    if (node != NULL) {
        tmp = node->origin;
        while (tmp != NULL) {
            if (tmp->closed == 0)
                nb_cells++;
            tmp = tmp->next;
        }
    }
    return (nb_cells);
}

origin_t *init_origin(map_t *map)
{
    origin_t *node;
    open_t *open;

    if ((node = malloc(sizeof(origin_t))) == NULL ||
        (open = malloc(sizeof(open_t))) == NULL)
        return (NULL);
    open->x = 0;
    open->y = 0;
    open->h_cost = (map->largeur - 1) * 10 + (map->hauteur - 1) * 10;
    open->closed = 0;
    open->next = NULL;
    open->prev = NULL;
    node->origin = open;
    return (node);
}
