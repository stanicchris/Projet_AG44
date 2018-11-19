#ifndef GRAPH_H
#define GRAPH_H

#include "libs.h"
#include "Edge.h"
#include "Vertex.h"
#include "List.h"
#include "MatrixI.h"

class Graph
{
	public :
		Graph();
		~Graph();
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
		/* ce serait peut etre mieux de faire des vector de vertex et de edge, a voir ! */
		Edge* listEdge; /* liste des edges du graphe */
		Vertex* listVertex; /* liste des vertex */
		int sizeM; /* taille de la matrice */
		int sizeV; /* nb de sommet du graphe */
		int sizeE; /* nb d'arrete du graphe */
		int oriented; /* 1 : oriente, 0 non-oriente */
		int type; /* 1 liste , 0 martice */
		vector<vector<Vertex> > listadj; /* vecteur de la liste d'adjacence du graphe */
		MatrixI* matrixadj; /* pointeur vers la matrice d'adjacence du graphe */
};

#endif
