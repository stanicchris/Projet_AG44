#ifndef VERTEX_H
#define VERTEX_H

#include "libs.h"

using namespace std;

class Vertex
{
	public :
		Vertex();
		~Vertex();
		Vertex(int,int,unsigned int); // create a vertex with his propreties
		unsigned int getID() {return id; }
		unsigned int getRank() { return rank; }
        int getX(){return x;}
        int getY(){return y;}
		int getKey() { return key; }
		Vertex* getParent() { return parent; }
        void setID(int a){id=a;}
        void setX(int a){x=a;}
        void setY(int a){y=a;}
		void setRank(int a) { rank = a; }
		void setParent(Vertex* a) { parent = a; }
		void setKey(int a) { key = a; }
		Color getColor() { return color; }
		void setColor(Color c) { color = c; }
		unsigned int tm[2]; // time arriving and getting out the vertex
		Vertex* pred;
    private :
        unsigned int id;
		unsigned int rank;
		int key;
		Vertex* parent;
        int x; // x position
        int y; // y position
        Color color;
};

#endif