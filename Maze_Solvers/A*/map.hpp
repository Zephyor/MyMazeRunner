/*
** YNOV PROJECT 2022
** By: arthur.viard@ynov.com
** File description:
** Map Data mesh of the A* AI algorithm
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "node.hpp"

class Map {
public:
    /*
    Initializes terrain with all Nodes available to all units.
    */
    Map(int rows, int columns);

    ~Map();

    /*
    Changes values of _terrain to new values defined in this function.
    */
    void loadTestMap();

    /* int idToRow
    Returns the row based on the id
    */
    int idToRow(int id);

    /*
    Returns the column based on the id
    */
    int idToColumn(int id);

    /* int
    Returns the id based on the row and column
    */
    int positionToId(int row, int column);

    //Getters
    int getRows() const;
    int getColumns() const;
    Node** getNodesP() const;

private:
    //VARIABLES
    int _rows;
    int _columns;

    /* Node** _Nodes
    Pointer to an array of pointers to instances of Node object.
    _Nodes[i] points to a Node with id i.
    Example: _Nodes[20] points to a Node with id 20.
    */
    Node** _Nodes;                      

    //METHODS
    /* void setNeighbours(Node* Node, Node** Nodes)
    Sets neighbours of Nodes[id] (id = arg1) as pointers to other Nodes from array Nodes (arg2)
    */
    void setNeighbours(int id, Node** Nodes);

};

#endif /* !MAP_HPP_ */