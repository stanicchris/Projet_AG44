#include "libs.h"
#include "Vertex.h"

using namespace std;

/* voir le descriptif des methodes dans .h*/

Vertex::Vertex(){}

Vertex::~Vertex()
{
    delete suiv;
}

Vertex::Vertex(int a,int b,int Id)
{
    this->x=a;
    this->y=b;
    this->id = Id;
}

Vertex* Vertex::next()
{
    if(this->suiv!=NULL)
    {
        return this->suiv;
    }
    else
    {
        this->suiv = new Vertex();
        return this->suiv;
    }
}

void Vertex::next(Vertex* v)
{
    suiv= new Vertex();
    suiv = v;
}
