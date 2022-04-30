import random

class Cell:
    """ Une cellule dans le labyrinthe se trouvant entouré par le haut, le bas, la gauche et la droite """

    # Un mur sépare une paire de cellules dans les directions Haut-Bas ou Droite-Gauche.

    paires_murs = {'Haut': 'Bas', 'Bas': 'Haut', 'Droite': 'Gauche', 'Gauche': 'Droite'}

    def __init__(self, x, y):
        """Met la cellule sur (x,y).En premier elle est entourer de murs."""

        self.x, self.y = x, y
        self.murs = {'Haut': True, 'Bas': True, 'Droite': True, 'Gauche': True}

    def A_tous_ses_mur(self):

        return all(self.murs.values())

    def mur_detruit(self, other, mur):
        """Abattre le mur entre la cellule et l'autre."""

        self.murs[mur] = False
        other.murs[Cell.paires_murs[mur]] = False

class Maze:
    """Un labyrinthe , represente par une grille de cellules."""

    def __init__(self, nx, ny, ix=0, iy=0):
        """Intialise la grille du labyrinthe .
        Le labyrinthe est constitué de nx x ny cellules et sera construit en commençant
        à la cellule indexée à (ix, iy)..
        """

        self.nx, self.ny = nx, ny
        self.ix, self.iy = ix, iy
        self.maze_map = [[Cell(x, y) for y in range(ny)] for x in range(nx)]

    def cell_at(self, x, y):
        """Retourner l'objet Cellule à (x,y)."""

        return self.maze_map[x][y]

    def __str__(self):
        """Renvoie une représentation du labyrinthe sous forme de chaîne de caractères.."""

        maze_rows = ['-' * self.nx * 2]
        for y in range(self.ny):
            maze_row = ['|']
            for x in range(self.nx):
                if self.maze_map[x][y].murs['Droite']:
                    maze_row.append(' |')
                else:
                    maze_row.append('  ')
            maze_rows.append(''.join(maze_row))
            maze_row = ['|']
            for x in range(self.nx):
                if self.maze_map[x][y].murs['Bas']:
                    maze_row.append('-+')
                else:
                    maze_row.append(' +')
            maze_rows.append(''.join(maze_row))
        return '\n'.join(maze_rows)

    def find_valid_neighbours(self, cell):
        """Renvoie une liste de voisins non visités à la cellule."""

        delta = [('Gauche', (-1, 0)),
                 ('Droite', (1, 0)),
                 ('Bas', (0, 1)),
                 ('Haut', (0, -1))]
        voisins = []
        for direction, (dx, dy) in delta:
            x2, y2 = cell.x + dx, cell.y + dy
            if (0 <= x2 < self.nx) and (0 <= y2 < self.ny):
                voisin = self.cell_at(x2, y2)
                if voisin.A_tous_ses_mur():
                    voisins.append((direction, voisin))
        return voisins

    def make_maze(self):
        # Nombre total de cellules.
        n = self.nx * self.ny
        cell_stack = []
        current_cell = self.cell_at(self.ix, self.iy)
        # Nombre total de cellules visitées pendant la construction du labyrinthe.
        nv = 1

        while nv < n:
            voisins = self.find_valid_neighbours(current_cell)

            if not voisins:
                # Nous avons atteint une impasse : retour en arrière.
                current_cell = cell_stack.pop()
                continue

            # Choisissez une cellule voisine au hasard et déplacez-vous vers elle.
            direction, next_cell = random.choice(voisins)
            current_cell.mur_detruit(next_cell, direction)
            cell_stack.append(current_cell)
            current_cell = next_cell
            nv += 1