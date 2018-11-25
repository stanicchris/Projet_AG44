#include "Vertex.h"

Vertex::Vertex(){}

Vertex::~Vertex(){}

Vertex::Vertex(int a,int b,int Id) {
    this->x=a;
    this->y=b;
    this->id = Id;
}

void Vertex::next(Vertex* v) {suiv = v;}
