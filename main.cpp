#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cstdlib>     // bibliotheque c standart
#include <iostream>    // flux d'entree sortie
#include <iomanip>     // manipulateurs de flux

#include "MatrixI.h"
#include "List.h"
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"
#include "Heap.h"

using namespace std;

int main(int argc, char **argv)
{
    Graph* graph = new Graph();
    List* l = new List();
    l->disp();
    free(graph);
    free(l);
    /*Vertex* v1 = new Vertex();
    Vertex* v2 = new Vertex();
    Vertex* v3 = new Vertex();
    Vertex* v4 = new Vertex();
    //Edge* e = new Edge(v1,v2);
    v1->setID(1);
    graph->ajouteVertex(v1);
    v2->setID(2);
    graph->ajouteVertex(v2);
    v3->setID(3);
    graph->ajouteVertex(v3);
    v4->setID(4);
    graph->ajouteVertex(v4);
    graph->display();
    cout << endl;
    graph->deleteVertex(2);
    graph->display();*/

    /*int** p = (int**) malloc(sizeof(int*)*2);
    for(int i=0;i<2;i++)
    {
        p[i] = (int*) malloc(sizeof(int)*2);
        for(int j=0;j<2;j++)
        {
            p[i][j]=i+j;
        }
    }
    cout << p[0][0] << "\t" << p[0][1] << endl;
    cout << p[1][0] << "\t" << p[1][1] << endl;


    p = (int**) malloc(sizeof(int*)*3);
    for(int i=0;i<3;i++)
    {
        p[i] = (int*) malloc(sizeof(int)*3);
        for(int j=0;j<3;j++)
        {
            p[i][j]=i+j;
        }
    }
    cout << p[0][0] << "\t" << p[0][1] << "\t" << p[0][2] << endl;
    cout << p[1][0] << "\t" << p[1][1] << "\t" << p[1][2] << endl;
    cout << p[2][0] << "\t" << p[2][1] << "\t" << p[2][2] << endl;
    free(p); //on utilise free() lorqu'il y a un malloc(), sinon on utilise delete*/
	return 0;
}

