/*
** YNOV PROJECT 2022
** by: arthur.viard@ynov.com
** File description :
** A_STAR solver ia header with struct declaration && function storing
*/

#ifndef ASTAR_H_
# define ASTAR_H_

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

typedef struct	s_open
{
  int		x;
  int		y;
  int		h_cost;
  int		closed;
  struct s_open	*next;
  struct s_open	*parent;
}		open_t;

typedef struct	s_origin
{
  open_t	*origin;
}		origin_t;

typedef struct	s_map
{
  int		hauteur;
  int		largeur;
  char		**map;
}		map_t;

int get_min(origin_t *);

// Structure init
open_t    *return_current(origin_t *, int);
origin_t  *close_current_from_open(origin_t *, open_t *);
origin_t  *init_origin(map_t *);

int is_it_closed(origin_t *, int, int);
int is_it_in_open(origin_t *, int, int);

/* MAP TREATMENT */
void  map_printer(map_t *, int);
int	  map_recuperation(map_t *, char *);

int   add_neighbor_in_open(origin_t *, open_t *);
int   count_cells(origin_t *);
int   astar(map_t *, origin_t *);

/* ERROR TREATMENT */
void  my_putsterror(char *);

#endif /* !ASTAR_H_ */
