/*
** YNOV PROJECT 2022
** By: arthur.viard@ynov.com
** File description:
** 
*/

#include "A_Star.hpp"

void A_Star::engineAStar(Node* start, Node* end) {

    std::vector<Node*> openNodes;

    start->setG(0);
    start->setH(start->calculateH(end));

    //Add the start Node to openNodes
    openNodes.push_back(start);

    //Begin the loop
    bool pathFound = false;
    Node* currentNode = nullptr;

    while (!pathFound) {

        //Choose the most suitable Node to visit
        if (openNodes.size() != 0) {
            //Sort the vector, Node with the lowest cost is at the end
            std::sort(openNodes.begin(), openNodes.end(), compareNodesF);
            currentNode = openNodes[openNodes.size() - 1];
        }
        else {
            //Out of open Nodes, path not found
            break;
        }

        //Remove the pointer to the current Node from the openNodes vector, as I'm about to visit the Node
        openNodes.pop_back();

        //Set the current Node as visited
        currentNode->setWasVisited(true);

        //Analyze neighbours
        std::vector<Node*>* neighbours = currentNode->getNeighboursP();
        for (int i = 0; i < neighbours->size(); i++) {

            //If the neighbour Node was already checked, skip it.
            //If the unit cannot move through the neighbour Node, also skip it.

            if (!(*neighbours)[i]->getWasVisited() && (*neighbours)[i]->getType() == Node::TerrainAvailability::ALL) {

                //This can happen multiple times per Node

                //Set G value
                /*
                I first need to check if the neighbour Node is diagonal or not.
                If it's diagonal, I would add 14 to the current G, otherwise 10.
                I only change the G value if the new value would be smaller than
                the current one.
                */

                int G_increase = currentNode->isNeighbourDiagonal((*neighbours)[i]) ? 14 : 10;

                if (currentNode->getG() + G_increase < (*neighbours)[i]->getG()) {
                    (*neighbours)[i]->setG(currentNode->getG() + G_increase);

                    //Set the parent
                    //Only if the new G is smaller than the previous G
                    (*neighbours)[i]->setParentP(currentNode);

                }

                //This can only happen once per Node
                if ((*neighbours)[i]->getH() == INT_MAX) {
                    //Set H value
                    int H = (*neighbours)[i]->calculateH(this->_mapP->getNodesP()[end->getId()]);
                    (*neighbours)[i]->setH(H);

                    if (H == 0) {
                        pathFound = true;
                    }

                    //Add this Node to the vector of open Nodes
                    openNodes.push_back((*neighbours)[i]);
                }
            }
        }
    }    
}

bool A_Star::compareNodesF(Node* a, Node* b) { 
    //Sorts pointers to Node objects based on their F values in descending order
    return (a->getF() > b->getF());
}