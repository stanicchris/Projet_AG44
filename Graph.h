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
		// delete an edge by specifying his ID
		void deleteVertex(unsigned int);
		void deleteEdge(unsigned int);
		//  dusplay the ID of all the vertices and edges of the graph
		void display(); // choose which function to use (O/NO)
		void display_o();
		void display_n();
		// build an adjacency matrix
		void graph_o_matrix(ifstream&);
		void graph_n_matrix(ifstream&);
		// build an adjacency list
		void graph_o_list(ifstream&);
		void graph_n_list(ifstream&);
		void file2graph(); // build the graph using the file graph_file.txt
		void create_n_edge(Vertex*, Vertex*); //build an oriented edge for the two vertex
		void create_o_edge(Vertex*, Vertex*);
		// switch between a matrix or a list for the 2 types of graph
		void o_list2matrix();
		void n_list2matrix();
		void o_matrix2list();
		void n_matrix2list();
		Edge* is_n_edge(Vertex*, Vertex*); // check if the vertices are linked by an non-oriented edge
		Edge* is_o_edge(Vertex*, Vertex*);
		//------------ only oriented graph functions ------
		unsigned int graph_connexe(); // check if the graph is related (connexe)
		//return number of vertex recheable from the vertex listVertex[0]
		unsigned int pathes_list_prefixe(unsigned int); //adjacency list representation
		unsigned int pathes_matrix_prefixe(unsigned int); //adjacency matrix representation
		//-------------------------------------------------
		//--------------- search functions ----------------
		void dfs(Vertex*);
		void dfs_visit(Vertex*, unsigned int &);
		//-------------------------------------------------
		void print_dfs_list(); //display the dfs list resulting from the dfs search
private :
	vector<Edge*> listEdge;
	vector<Vertex*> listVertex;
	unsigned int sizeV; // = listVertex.size()
	unsigned int sizeE; // = listEdge.size()
	vector<vector<Vertex*> > adjlist; // adjacency list
	vector<vector<unsigned int> > adjmatrix; //adjacency matrix
	unsigned int type; // 1 oriented / 0 non-oriented
	unsigned int adj; // 1 list / 0 matrix
	vector<unsigned int> dfs_list;
};

#endif
