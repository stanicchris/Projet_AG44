#ifndef EDGE_H
#define EDGE_H

#include "libs.h"
#include "Vertex.h"

/* lorqu'on créer une arrete, on lui associe necessairement deux sommets */
class Edge
{
	public :
		Edge(); ///USELESS
		~Edge();
		Edge(Vertex*,Vertex*,unsigned int,unsigned int); // créer un edge avec ses vertexs, son ID et son type : 1 oriente/0 non oriente
        int getPoids(){return poids;}
        unsigned int getID(){return id;}
        Vertex* getSrc(){return src;}
        Vertex* getDest(){return dest;}
		Vertex* get_v0() { return vertex[0]; }
		Vertex* get_v1() { return vertex[1]; }
        void setPoids(int a){poids=a;}
        void setID(int a){id=a;}
        void setSrc(Vertex* s){src=s;}
        void setDest(Vertex* d){dest=d;}
		void set_v0(Vertex* v0);
		void set_v1(Vertex* v1);
		int is_n_edge(Vertex*, Vertex*); // verifie si l'edge non oriente relie ces vertexs
		int is_o_edge(Vertex*, Vertex*);
	private :
		// vertexs d'un edge oriente
        Vertex* src;
        Vertex* dest;
		// vertexs d'un edge non oriente
		vector<Vertex*> vertex;
        int poids;
        unsigned int id;
		unsigned int type; // 1 oriente/0 non-oriente
};

#endif
