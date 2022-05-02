/*
** YNOV PROJECT 2022
** by: arthur.viard@ynov.com
** File description :
** map treatment
*/

#include "../include/astar.h"

/*
#include <mysql/mysql.h>
void mysql_connect()
{
    MYSQL *connexion;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = ADDR;
    char *user = LOG;
    char *password = PSW;
    char *database = DB;

    connexion = mysql_init(NULL);

    if (!mysql_real_connect(connexion, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(connexion));
        exit(1);
    }

    if (mysql_query(connexion, "show tables")) {
      fprintf(stderr, "%s\n", mysql_error(connexion));
      exit(1);
    }
    res = mysql_use_result(connexion);

    printf("MySQL Tables in mysql database:\n");
    while ((row = mysql_fetch_row(res)) != NULL)
    	printf("%s \n", row[0]);
    

    mysql_free_result(res);
    mysql_close(connexion);
}
*/

void map_printer(map_t *map, int rt)
{
    FILE *fptr = NULL;
    char *path = "../AstarSolvedMap.txt";
    int i = 0;

    fptr = fopen(path, "w");
 
    if (fptr == NULL) {
        printf("File does not exists \n");
        return;
    }
    printf("Algorithm A* runtime: %d ms\n", rt);
    while (i != map->hauteur) {
        fprintf(fptr, "%s\n", map->map[i]);
        ++i;
    }
    //mysql_connect();
    fclose(fptr);
}

// Check the map validity -> '*' for travel spaces && 'X' for walls.
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
