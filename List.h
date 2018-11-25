#ifndef LIST_H
#define LIST_H

#include "libs.h"
#include "Vertex.h"
using namespace std;

class Graph; //créer l'interdépendance entre list et graph, evite les boucles d'include
class List
{
	public :
		List(); //useless
		~List();
        List(Graph*);
        void disp();
	private :
		int l_size;
		Vertex** vlist;
};

#endif
