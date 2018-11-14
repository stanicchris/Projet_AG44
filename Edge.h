#ifndef EDGE_H
#define EDGE_H

<<<<<<< HEAD
#include "libs.h"
=======
>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
#include "Vertex.h"

//lorqu'on créer une arrete, on lui associe necessairement deux sommets
class Edge
{
	public :
		Edge();// A ne pas utiliser !
		~Edge();
		Edge(Vertex*,Vertex*); //créer une arrete avec ses sommets
        int getPoids(){return this->poids;}
        int getID(){return this->id;}
        Vertex* getSrc(){return this->src;}
        Vertex* getDest(){return this->dest;}
        void setPoids(int a){this->poids=a;}
        void setID(int a){this->id=a;}
        void setSrc(Vertex* s){this->src=s;}
        void setDest(Vertex* d){this->dest=d;}
        Edge* next();
        void next(Edge*);// construit l'arrete suivant dans la liste des sommets du graphe
    private :
        Vertex* src;
        Vertex* dest;
        Vertex* v[2]; //contient les deux vecteurs
        int poids;
        int id;
        Edge* suiv;
};

#endif
