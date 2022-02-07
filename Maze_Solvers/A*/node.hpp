/*
** YNOV PROJECT 2022
** By: arthur.viard@ynov.com
** File description:
** Nodes Data mesh of the A* AI algorithm
*/

#ifndef NODE_HPP_
#define NODE_HPP_

#include <vector>
#include "map.hpp"

class Node {
public:
    enum TerrainAvailability {
        ALL,
        AIR,
        NONE
    };

    /* Node
    Creates the object and initializes _id, _type, _mapP.
    */
    Node(int id, TerrainAvailability type, Map* mapP);

    /* int calculateH
    Calculates H (the distance between this Node and the end Node).
    */
    int calculateH(Node* endNode);

    /* bool isNeighbourDiagonal
    Returns true if the neighbour Node is touching this Node by a corner.
    Returns false if the neighbour Node is touching this Node by an edge.
    */
    bool isNeighbourDiagonal(Node* neighbour);

    /* void reset
    Resets all member variables to their default state.
    */
    void reset();

    //Setters
    void setType(TerrainAvailability type);
    void setNeighbours(std::vector<Node*> neighbours);
    void setWasVisited(bool wasVisited);
    void setG(int G);
    void setH(int H);
    void setParentP(Node* parentP);

    //Getters
    int getId();
    TerrainAvailability getType();
    std::vector<Node*>* getNeighboursP();
    bool getWasVisited();
    int getG();     
    int getH();
    int getF();
    Node* getParentP();

private:
    int _id;
    TerrainAvailability _type;
    Map* _mapP;                         //Pointer to the map object, allows the use of utility functions
                                        //(switching between columns and rows and id)
    std::vector<Node*> _neighbours;     //Vector holding pointers to neighbour Nodes
    bool _wasVisited;
    int _G;                             //Distance from start
    int _H;                             //Minimal distance to end
    //int _F doesn't have to be stored, as I can get it by summing up _G and _H
    Node* _parentP;

};

#endif /* !NODE */