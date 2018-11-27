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
		unsigned int get_type() {return type;}
		unsigned int get_adj() {return adj;}
		void change_adj(){adj = 1-adj;}
		// supprime un vertex ou un edge  en specifiant son ID
		void deleteVertex(unsigned int);
		void deleteEdge(unsigned int);
		//affiche les id de tous les vertex et edge du graphe oriente
		void display(); // choisit l'affichage en fonction du type de graphe
		void display_o();
		void display_n();
		// construit une matrice d'adjacence pour graphe
		void graph_o_matrix(ifstream&);
		void graph_n_matrix(ifstream&);
		// construit une liste d'adjacence pour graphe oriente
		void graph_o_list(ifstream&);
		void graph_n_list(ifstream&);
		void file2graph(); // construit le graphe a partir du fichier graph_file.txt
		void create_n_edge(Vertex*, Vertex*);
		void create_o_edge(Vertex*, Vertex*);
		void o_list2matrix();
		void n_list2matrix();
		void o_matrix2list();
		void n_matrix2list();
		Edge* is_n_edge(Vertex*, Vertex*); // verifie si un non oriente relie ces vertexs
		Edge* is_o_edge(Vertex*, Vertex*);
private :
        vector<Edge*> listEdge;
        vector<Vertex*> listVertex;
        unsigned int sizeV; // = listVertex.size()
	unsigned int sizeE; // = listEdge.size()
        vector<vector<Vertex*> > adjlist; //liste d'adjacence du graphe
	unsigned int** adjmatrix; //matrice d'adjacence du graphe
	unsigned int type; // 1 oriente / 0 non-oriente
	unsigned int adj; // 1 liste / 0 matrice
};

#endif
