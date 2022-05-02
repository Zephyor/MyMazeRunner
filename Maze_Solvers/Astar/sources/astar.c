/*
** YNOV PROJECT 2022
** by: arthur.viard@ynov.com
** File description :
** A_STAR Algorithm
*/

#include <time.h>
#include "../include/astar.h"

static void get_neighbours_pos(open_t *neighbor, int y, int x)
{
    neighbor->y = y;
    neighbor->x = x;
}

static open_t  *lowest_heuristique_cost(origin_t *f)
{
    open_t	*tmp;
    int		i = 0;
    int		saved = 0;
    int		min = 0;

    if (f != NULL && f->origin != NULL) {
        tmp = f->origin;
        if ((min = get_min(f)) == -1)
	          return (NULL);
        while (tmp != NULL) {
        	  if (tmp->closed == 0 && min >= tmp->h_cost) {
        	      saved = i;
        	      min = tmp->h_cost;
        	  }
        	  i++;
        	  tmp = tmp->next;
        }
        return (return_current(f, saved));
    }
    return (NULL);
}

static int set_neighbours(open_t *neighbor, map_t *map, origin_t *f, open_t *current)
{
    int		ret = 0;

    if (neighbor->x >= 0 && neighbor->x < map->largeur && neighbor->y >= 0 && neighbor->y < map->hauteur
        && map->map[neighbor->y][neighbor->x] != 'X' && (ret = is_it_closed(f, neighbor->y, neighbor->x)) != 1) {
        if (ret == -1)
    	    return (1);
        if ((ret = is_it_in_open(f, neighbor->y, neighbor->x)) != 1) {
    	    if (ret == -1)
    	        return (1);
    	    neighbor->closed = 0;
    	    neighbor->h_cost = ((map->largeur - 1)- neighbor->x) * 10 + ((map->hauteur - 1) - neighbor->y) * 10;
    	    neighbor->parent = current;
    	    if (add_neighbor_in_open(f, neighbor) == 1)
    	        return (1);
    	}
    }
    return (0);
}

static int get_neighbours(map_t *map, origin_t *f, open_t *current)
{
    int i = 0;
    open_t	*neighbor;

    while (i < 4) {
        if ((neighbor = malloc(sizeof(open_t))) == NULL)
            return (1);
        if (i == 0)
            get_neighbours_pos(neighbor, current->y, current->x - 1);
        else if (i == 1)
            get_neighbours_pos(neighbor, current->y, current->x + 1);
        else if (i == 2)
            get_neighbours_pos(neighbor, current->y - 1, current->x);
        else if (i == 3)
            get_neighbours_pos(neighbor, current->y + 1, current->x);
        if (set_neighbours(neighbor, map, f, current) == 1)
            return (1);
        ++i;
    }
    return (0);
}

int astar(map_t *map, origin_t *node) 
{
    open_t *current;
    clock_t begin = clock();
    unsigned long runtime = 0;


    while (count_cells(node) > 0) {
        if ((current = lowest_heuristique_cost(node)) == NULL)
            return (-1);
        close_current_from_open(node, current);
        if (current->y == map->hauteur - 1 && current->x == map->largeur - 1) {
            while (current != NULL) {
                map->map[current->y][current->x] = 'o';
                current = current->parent;
            }
            clock_t end = clock();
            runtime = (end - begin) * 1000 / CLOCKS_PER_SEC;
            return ((int)runtime);
        }
        if (get_neighbours(map, node, current) == 1)
            return (-1);
    }   
    my_putsterror("No solution found\n");
    return (1);
}
