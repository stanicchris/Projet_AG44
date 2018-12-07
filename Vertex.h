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
        int getX(){return x;}
        int getY(){return y;}
        void setID(int a){id=a;}
        void setX(int a){x=a;}
        void setY(int a){y=a;}
		Color getColor() { return color; }
		void setColor(Color c) { color = c; }
    private :
        unsigned int id;
        int x; // x position
        int y; // y position
		Color color;
};

#endif