/*
** YNOV PROJECT 2022
** by: arthur.viard@ynov.com
** File description :
** map treatment
*/

#include "../include/astar.h"


/*if tpm == true && tmp->closed = 0 significate that we are at the map's end 
and we have found the shortest path and return his heuristic cost. on error return -1 */

int get_min(origin_t *f)
{
    open_t	*tmp = f->origin;

    while (tmp != NULL && tmp->closed != 0)
        tmp = tmp->next;
    if (tmp == NULL)
        return (-1);
    if (tmp->closed == 0)
        return (tmp->h_cost);
    return (-1);
}

// return the current node
open_t *return_current(origin_t *node, int pos)
{
    int i = 0;
    open_t *tmp = node->origin;

    while (tmp != NULL && i != pos) {
        ++i;
        tmp = tmp->next;
    }
    return (tmp);
}

// close the current node permit us to move in map linked list / return NULL on error
origin_t *close_current_from_open(origin_t *node, open_t *current)
{
    open_t *tmp = NULL;

    if (node == NULL || current == NULL)
        return (NULL);
    tmp = node->origin;
    while (tmp != NULL) {
        if (tmp->x == current->x && tmp->y == current->y) {
            tmp->closed = 1;
        return (node);
        }
        tmp = tmp->next;
    }
    return (NULL);
}

int is_it_closed(origin_t *node, int y, int x)
{
    open_t *tmp = NULL;

    if (node != NULL) {
        tmp = node->origin;
        while (tmp != NULL) {
            if (y == tmp->y && x == tmp->x && tmp->closed == 1)
                return (1);
            tmp = tmp->next;
        }
        return (0);
    }
    return (-1);
}

int is_it_in_open(origin_t *node, int y, int x)
{
    open_t *tmp = NULL;

    if (node != NULL) {
        tmp = node->origin;
        while (tmp != NULL) {
            if (y == tmp->y && x == tmp->x && tmp->closed == 0)
                return (1);
            tmp = tmp->next;
        }
        return (0);
    }
    return (-1);
}
