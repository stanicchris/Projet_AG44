#include "Graph.h"

/* voir le descriptif des methodes dans .h*/

Graph::Graph()
{
    listEdge = NULL;
    listVertex = NULL;
	adjmatrix = NULL;
    sizeV = 0;
    sizeM = 0;
}

Graph::~Graph()
{
	delete listEdge;
	delete listVertex;
	delete adjmatrix;
}

void Graph::display()
{
    /* A ecrire avec un vector */
}

void Graph::ajouteVertex(Vertex* v) /* l'ajout se fait par le fichier graph_file.txt */
{
    if(sizeV == 0) //yes
    {
        listVertex=v;
    }
    else
    {
        Vertex* temp;
        int s=0;
        temp=listVertex;
        while(s<sizeV-1)
        {
            temp=temp->next();
            s++;
        }
        temp->next(v);
    }
    sizeV++;
}

void Graph::deleteVertex(int id)
{
    if(sizeV<=0 || id<1 || id>sizeV)
    {
        cout << "La liste est vide ou il y a un probleme" << endl;
    }
    else if(sizeV==1)
    {
        Vertex* temp;
        temp = listVertex;
        listVertex = NULL;
        delete temp;
        sizeV--;
    }
    else if(id==1)
    {
        Vertex* temp;
        Vertex* temp1;
        temp = listVertex;
        listVertex = temp->next();
        temp->next(NULL);
        delete temp;
        int i=0;
        temp1 = listVertex;
        sizeV--;
        while(i<sizeV)
        {
            temp1->setID(temp1->getID()-1);
            temp1 = temp1->next();
            i++;
        }
    }
    else
    {
        Vertex* temp;
        Vertex* temp1;
        Vertex* temp2;
        int s1=0, s2=0;
        temp1=listVertex;
        temp2=listVertex;
        while(temp1->next()->getID()!= id)
        {
            temp1=temp1->next();
            s1++;
        }
        while(s2<sizeV-2)
        {
            temp2=temp2->next();
            s2++;
        }
        temp=temp1->next();
        temp2->next()->setID(temp->getID());
        temp1->next(temp2->next());
        temp2->next(NULL);
        temp1->next()->next(temp->next());
        temp->next(NULL);
        delete temp;
        sizeV--;
    }
}

void Graph::ajouteEdge(Edge* e)
{
    if(sizeE == 0)
    {
        listEdge=e;
    }
    else
    {
        Edge* temp;
        int s=0;
        temp=listEdge;
        while(s<sizeE-1)
        {
            temp=temp->next();
            s++;
        }
        temp->next(e);
    }
    sizeE++;
}

void Graph::deleteEdge(int id)
{
    if(sizeE<=0 || id<1 || id>sizeE)
    {
        cout << "La liste est vide ou il y a un probleme" << endl;
    }
    else if(sizeE==1)
    {
        Edge* temp;
        temp = listEdge;
        listEdge = NULL;
        delete temp;
        sizeE--;
    }
    else if(id==1)
    {
        Edge* temp;
        Edge* temp1;
        temp = listEdge;
        listEdge = temp->next();
        temp->next(NULL);
        delete temp;
        int i=0;
        temp1 = listEdge;
        sizeE--;
        while(i<sizeE)
        {
            temp1->setID(temp1->getID()-1);
            temp1 = temp1->next();
            i++;
        }
    }
    else
    {
        Edge* temp;
        Edge* temp1;
        Edge* temp2;
        int s1=0, s2=0;
        temp1=listEdge;
        temp2=listEdge;
        while(temp1->next()->getID()!= id)
        {
            temp1=temp1->next();
            s1++;
        }
        while(s2<sizeE-2)
        {
            temp2=temp2->next();
            s2++;
        }
        temp=temp1->next();
        temp2->next()->setID(temp->getID());
        temp1->next(temp2->next());
        temp2->next(NULL);
        temp1->next()->next(temp->next());
        temp->next(NULL);
        delete temp;
        sizeE--;
    }
}

Edge* Graph::voisins(Vertex* u,Vertex* v)
{
    if(listEdge != NULL)
    {
        Edge* temp = listEdge;
        if((temp->getDest() == v && temp->getSrc() == u) || (temp->getDest() == u && temp->getSrc() == v))
            {
                return temp;
            }
        else
        {
            while(temp->next() != NULL)
            {
                if((temp->getDest() == v && temp->getSrc() == u) || (temp->getDest() == u && temp->getSrc() == v))
                    {
                        return temp;
                    }
                else
                    {temp=temp->next();}
            }
        }
        if((temp->getDest() == v && temp->getSrc() == u) || (temp->getDest() == u && temp->getSrc() == v))
            {
                return temp;
            }
        else
        {
            return NULL;
        }
    }
    else
        {
            return NULL;
        }
}

