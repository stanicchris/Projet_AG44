#ifndef VERTEX_H
#define VERTEX_H

#include "libs.h"

using namespace std;

//un sommet ne peut faire partie que d'un seul graphe a la fois
class Vertex
{
	public :
		Vertex();
		~Vertex();
		Vertex(int,int,unsigned int); // créer un sommet avec ses coordonnees et un ID
		unsigned int getID() {return id; }
        int getX(){return x;}
        int getY(){return y;}
        void setID(int a){id=a;}
        void setX(int a){x=a;}
        void setY(int a){y=a;}
    private :
        unsigned int id;
        int x; // position X dans l'espace
        int y; // position Y dans l'espace
};

#endif