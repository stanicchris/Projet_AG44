#include "Vertex.h"

Vertex::Vertex() {}

Vertex::~Vertex(){}

Vertex::Vertex(int a,int b,unsigned int id2) {
    x=a;
    y=b;
    id = id2;
    color = WHITE;
	parent = this;
	rank = 0;
}
