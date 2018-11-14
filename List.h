#ifndef LIST_H
#define LIST_H

<<<<<<< HEAD
#include "libs.h"
=======
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>

>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
#include "Vertex.h"

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
