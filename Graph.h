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
		void graph_o_matrix(ifstream&); //construit une matrice d'adjacence pour graphe oriente
		void graph_n_matrix(ifstream&); //construit une matrice d'adjacence pour graphe non oriente
		void graph_o_list(ifstream&); //construit une liste d'adjacence pour graphe oriente
		void graph_n_list(ifstream&); //construit une liste d'adjacence pour graphe non oriente
		void file2graph(); /* construit le graphe a partir du fichier graph_file.txt */
		void o_list2matrix();
		void n_list2matrix();
		void o_matrix2list();
		void n_matrix2list();
		Vertex* vertex_id(int); //retourne le vertex n°id du graphe
private :
        Edge* listEdge;
        Vertex* listVertex;
        int sizeV; //nb de sommet du graphe = taille de la matrice
        int sizeE; //nb d'arrete du graphe
        vector<vector<Vertex*> > adjlist; //liste d'adjacence du graphe
        int** adjmatrix; //matrice d'adjacence du graphe
		int type; // 1 oriente / 0 non-oriente
		int adj; // 1 liste / 0 matrice
};

#endif
