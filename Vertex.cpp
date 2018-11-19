#include "libs.h"
#include "Vertex.h"

/* voir le descriptif des methodes dans .h*/

Vertex::Vertex(){this->next = NULL;}

Vertex::~Vertex() {delete next;}

Vertex::Vertex(int a,int b,int Id) {
    this->x=a;
    this->y=b;
    this->id = Id;
}

Vertex* Vertex::get_next() {return this->next;}

void Vertex::set_next(Vertex* v) {if(v!=NULL) {this->next = v;}}
