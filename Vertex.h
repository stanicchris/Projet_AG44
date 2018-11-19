#ifndef VERTEX_H
#define VERTEX_H

#include "libs.h"

//un sommet ne peut faire partie que d'un seul graphe a la fois
class Vertex
{
	public :
		Vertex();
		~Vertex();
		Vertex(int,int,int); /* créer un sommet avec ses coordonnees et un ID */
		int getID(){return this->id;}
		int getX(){return this->x;}
		int getY(){return this->y;}
		void setID(int a){this->id=a;}
		void setX(int a){this->x=a;}
		void setY(int a){this->y=a;}
		Vertex* get_next();/* renvoie this->next; */
		void set_next(Vertex*); /* créer this->next */
	private :
		int id;
		int x; /* position X dans l'espace */
		int y; /* position Y dans l'espace */
		Vertex* next; /* permet de parcourir listVertex dans Graph */
};

#endif
