#ifndef GRAPH_H
#define GRAPH_H

<<<<<<< HEAD
#include "libs.h"

=======
>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
#include "Edge.h"
#include "Vertex.h"
#include "List.h"
#include "MatrixI.h"

<<<<<<< HEAD
using namespace std;

=======
>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
class Graph
{
	public :
		Graph();
		~Graph();
<<<<<<< HEAD
		void ajouteVertex(Vertex*); //ajoute un sommet au graphe
		void ajouteEdge(Edge*); //ajoute une arrete au graphe
		void deleteVertex(int); //supprime un sommet en specifiant son id
		void deleteEdge(int); //supprime une arrete en specifiant son id
		void display(); //affiche les id de tous les sommets du graphe
		Edge* voisins(Vertex*,Vertex*); //permet de savoir si deux sommets sont voisins dans un graphe et si c'est le cas retourne l'arrete sinon NULL
		void graph_o_matrix(); //construit une matrice d'adjacence pour graphe oriente
		void graph_n_matrix(); //construit une matrice d'adjacence pour graphe non oriente
		void graph_o_list(); //construit une liste d'adjacence pour graphe oriente
		void graph_n_list(); //construit une liste d'adjacence pour graphe non oriente
		void file2graph(); /* construit le graphe a partir du fichier graph_file.txt */

private :
        Edge* listEdge;
        Vertex* listVertex;
        int sizeM; //taille de la matrice
        int sizeV; //nb de sommet du graphe
        int sizeE; //nb d'arrete du graphe
        vector<vector<Vertex> > listadj; //pointeur vers la liste d'adjacence du graphe
        MatrixI* adjmatrix; //pointeur vers la matrice d'adjacence du graphe
=======
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
>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
};

#endif
