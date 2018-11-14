#ifndef VERTEX_H
#define VERTEX_H

<<<<<<< HEAD
#include "libs.h"

=======
>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
//un sommet ne peut faire partie que d'un seul graphe a la fois
class Vertex
{
	public :
		Vertex();
		~Vertex();
		Vertex(int,int,int); // créer un sommet avec ses coordonnees et un ID
        int getID(){return this->id;}
        int getX(){return this->x;}
        int getY(){return this->y;}
        void setID(int a){this->id=a;}
        void setX(int a){this->x=a;}
        void setY(int a){this->y=a;}
        Vertex* next();// renvoie le sommet suivant de la liste des sommets du graphe, utilisé uniquement par le graphe
        void next(Vertex*);// construit le sommet suivant dans la liste des sommets du graphe
    private :
        int id;
        int x; // position X dans l'espace
        int y; // position Y dans l'espace
        Vertex* suiv; // permet de parcourir la liste des sommets d'un graphe, ne s'utilise que si le sommet fait partie d'un graphe
};

#endif
