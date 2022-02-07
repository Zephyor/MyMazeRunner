/*
** YNOV PROJECT 2022
** By: arthur.viard@ynov.com
** File description:
** A_Star Data mesh of the A* AI algorithm
*/

#ifndef A_STAR_HPP_
#define A_STAR_HPP_

#define INT_MAX 244

#include "node.hpp"
#include "map.hpp"
#include <algorithm>

class A_Star {
    public:
        A_Star();        //Won't be used

        /* A_Star
        Creates the object and initializes _mapP
        */
        A_Star(Map* mapP);

        void engineAStar(Node*, Node*);

    private:        
        Map* _mapP;

        //Methods
        static bool compareNodesF(Node* a, Node* b);
};

#endif /* !A_STAR_HPP_ */