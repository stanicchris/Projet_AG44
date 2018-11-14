<<<<<<< HEAD
=======
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cstdlib>     // bibliotheque c standart
#include <iostream>    // flux d'entrÈe sortie
#include <iomanip>

>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
#include "Edge.h"

using namespace std;

<<<<<<< HEAD
/* voir le descriptif des methodes dans .h*/
=======
//voir l'objetctif des methodes dans le .h
>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a

Edge::Edge()
{
    this->poids = 0;
}

Edge::~Edge()
{
    delete src;
    delete dest;
    delete suiv;
}

Edge::Edge(Vertex* a,Vertex* Id)
{
    this->src=a;
    this->dest=Id;
}

Edge* Edge::next()
{
    if(this->suiv!=NULL)
    {
        return this->suiv;
    }
    else
    {
        this->suiv = new Edge();
        return this->suiv;
    }
}

void Edge::next(Edge* e)
{
    suiv = new Edge();
    suiv = e;
}
