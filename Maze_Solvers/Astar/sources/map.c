/*
** YNOV PROJECT 2022
** by: arthur.viard@ynov.com
** File description :
** map treatment
*/

#include "../include/astar.h"
#include <stdio.h>


void map_printer(map_t *map, int rt)
{
    FILE *fptr = NULL;
    char *path = "../../AstarSolvedMap.txt";
    int i = 0;

    fptr = fopen(path, "w");
 
    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
    printf("Algorithm A*: %d ms\n", rt);
    fprintf(fptr, "algoritm A*: %d ms\n", rt);
    while (i != map->hauteur) {
        fprintf(fptr, "%s\n", map->map[i]);
        ++i;
    }
    fclose(fptr);
}

// Check the map validity -> '*' for travel spaces && 'X' for walls. / important cast from ssize_t to int for map size check
static int	map_check_format(char *line, int largeur)
{
    int	i = 0;

    if ((int)strlen(line) != largeur)
        return (1);
    while (line[i] != '\0') {
        if (line[i] != '*' && line[i] != 'X')
          return (1);
        ++i;
    }
    return (0);
}

// The data struct already allocated / set map linked list with format check of the received data (open & close fd)
static int map_store_linked_list(map_t *map, char *av)
{
    int i = 0;
    FILE *fd;
    size_t len = 0;
    char *str = NULL;

    if ((fd = fopen(av, "r")) == NULL)
        return (1);
    while (getline(&str, &len, fd) != -1) {
        map->map[i] = strdup(str);
        map->map[i][map->largeur] = '\0';
        if (map_check_format(map->map[i], map->largeur) == 1)
            return (1);
        ++i;
    }
    fclose(fd);
    return (0);
}

// open map.txt & get map info (while getline to get the total map length) for futur storage with map_storing (open & close fd)
int map_recuperation(map_t *map, char *av)
{
    FILE *fd;
    char *str = NULL;
    size_t len = 0;

    map->hauteur = 0;
    if ((fd = fopen(av, "r")) == NULL)
        return (1);
    while (getline(&str, &len, fd) != -1) {
        map->hauteur = map->hauteur + 1;
    }
    map->largeur = strlen(str) - 1;
    fclose(fd);
    if ((map->map = malloc(sizeof(char *) * map->hauteur)) == NULL)
        return (1);
    if (map_store_linked_list(map, av) == 1)
      return (1);
    return (0);
}
