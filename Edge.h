#ifndef EDGE_H
#define EDGE_H

#include "libs.h"
#include "Vertex.h"

/* when we create an edge, we automaticaly associate him two vertices */
class Edge
{
	public :
	Edge(); ///USELESS
	~Edge();
	Edge(Vertex*,Vertex*,unsigned int,unsigned int); // create an edge with his propreties
	int getPoids(){return poids;}
	unsigned int getID(){return id;}
	Vertex* getSrc(){return src;}
	Vertex* getDest(){return dest;}
	Vertex* get_v0() { return vertex[0]; }
	Vertex* get_v1() { return vertex[1]; }
	unsigned int get_ID_Src(){return src->getID();}
    unsigned int  get_ID_Dest(){return dest->getID();}
	unsigned int  get_ID_v0() { return vertex[0]->getID(); }
	unsigned int  get_ID_v1() { return vertex[1]->getID(); }
    void setPoids(int a){poids=a;}
    void setID(int a){id=a;}
    void setSrc(Vertex* s){src=s;}
    void setDest(Vertex* d){dest=d;}
	void set_v0(Vertex* v0);
	void set_v1(Vertex* v1);
	void o_matrix2list();
	void n_matrix2list();
	private :
	// vertices of oriented graph
	Vertex* src;
	Vertex* dest;
	// vertices of non-oriented graph
	vector<Vertex*> vertex;
	int poids;
	unsigned int id;
	unsigned int type; // 1 oriented   0 non-oriented
};

#endif
