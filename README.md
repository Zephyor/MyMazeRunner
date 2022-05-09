# MyMazeRunner

Authors: axel.boudeau@ynov.com, nathan.mezou@ynov.com, arthur.viard@ynov.com

Links:

`https://trello.com/b/iLf0O6MX/mymazerunner`

## Introduction

Le but du projet est de développer un générateur et un solveur de labyrinthe (Parfait, imparfait) en local:
(Projet de base 28pts) (Fonctionalité ajouté 5pts multithreading et 8pts pour les 3 autres IAs et snapshots)

 1. Maze génération, python || JS || (12pts génération et édition de maze)
 2. Maze Solver, C || Algorithms: A*, Dijkstra, Tremaux, BrutForce. (multithreading, compétition IA)
 4. Bases de données, nosql. (4pts)

## Rôles

axel.boudeau@ynov.com : Gère la génération des deux types de labyrinthes (perfect maze & imperfect maze). 

arthur.viard@ynov.com & nathan.mezou@ynov.com : Se chargent de la conception des "IA" des solveurs (A*, ?Tremaux, ?Dijkstra, brutforce).

nathan.mezou@ynov.com: Se chargent de l'édition de la base de donnée.

## Usage

Géneration de la map en python dans le dossier "MyMazeRunner/Maze_Gen":

    $ python3 main.py 'x' 'y'
Le labyrinthe est placé dans le dossier "MyMazeRunner/Maze_Gen/deposit".

Compilation de l'ia A* en c grâce au makefile. Se rendre dans le dossier "MyMazeRunner/Maze_Solvers/Astar" puis compiler l'ia via un Makefile:


    // Utilisation du makefile.
    // génération du binaire
    $ make
    
    // suppression des fichiers .o (car avant de passer au binaire gcc passe 
    // d'abord une étape intermédiare)
    $ make clean
    
    // suppression des fichiers .o et du binaire
    $ make fclean

Maintenant nous pouvons éxécuter notre ia A* :

    $ ./final_astar/astar ../../Maze_Gen/deposit/"map.txt"
Labyrinthe résolue sera généré dans un format particulier et nous pourrons ensuite le récupérer avec notre front-end en react.
    
Se rendre au root du projet et aller dans le dossier "showmazev2" ou nous allons lancer react :

    // installation des paquets
    $ npm i
    
    // puis le serveur local
    $ npm run start

Il n'y a plus qu'a ouvrir l'url "http://localhost:3000" et cliquer sur le bouton sur la page pour récupérer le ficher "AstarSolvedMap.txt" dans "MyMazeRunner/Maze_Solvers". Le fichier sera interprété et afficher via un component react et des hooks. Plusieurs maps peuvent être affiché.