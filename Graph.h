#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "Vertex.h"
#include "List.h"
#include "MatrixI.h"

class Graph
{
	public :
		Graph();
		~Graph();
		void ajouteVertex(Vertex*); //ajoute un sommet au graph
		void ajouteEdge(Edge*);
		void deleteVertex(int); //supprime un sommet en specifiant son id
		void deleteEdge(int);
		void display(); //affiche les id de tous les sommets du graphe
		Edge* voisins(Vertex*,Vertex*); //permet de savoir si deux sommets sont voisins dans un graphe et si c'est le cas donne l'arrete sinon NULL
	private :
        Edge* listEdge;
        Vertex* listVertex;
        int sizeM; //taille de la matrice
        int sizeG; //nb de sommet du graphe
        int sizeE; //nb d'arrete du graphe
        List* adjlist;
        MatrixI* adjmatrix;
};

#endif
