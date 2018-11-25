#include "Edge.h"

Edge::Edge()
{
    this->poids = 0;
}

Edge::~Edge()
{
    delete src;
    delete dest;
    delete suiv;
}

Edge::Edge(Vertex* a,Vertex* Id)
{
    this->src=a;
    this->dest=Id;
}

Edge* Edge::next()
{
    if(this->suiv!=NULL)
    {
        return this->suiv;
    }
    else
    {
        this->suiv = new Edge();
        return this->suiv;
    }
}

void Edge::next(Edge* e)
{
    suiv = new Edge();
    suiv = e;
}
