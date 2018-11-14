<<<<<<< HEAD
#include "libs.h"
=======
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cstdlib>     // bibliotheque c standart
#include <iostream>    // flux d'entrÈe sortie
#include <iomanip>

>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
#include "Vertex.h"

using namespace std;

<<<<<<< HEAD
/* voir le descriptif des methodes dans .h*/
=======
//voir l'objetctif des methodes dans le .h
>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a

Vertex::Vertex(){}

Vertex::~Vertex()
{
    delete suiv;
}

Vertex::Vertex(int a,int b,int Id)
{
    this->x=a;
    this->y=b;
    this->id = Id;
}

Vertex* Vertex::next()
{
    if(this->suiv!=NULL)
    {
        return this->suiv;
    }
    else
    {
        this->suiv = new Vertex();
        return this->suiv;
    }
}

void Vertex::next(Vertex* v)
{
    suiv= new Vertex();
    suiv = v;
}
