#include "Graph.h"

using namespace std;

List::List()
{
    vlist = NULL;
}

<<<<<<< HEAD
List::~List()
{
	delete vlist;
}

=======
>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
List::List(Graph* g)
{
    vlist = NULL;
}

void List::disp()
{
    if (this->vlist == NULL)
    {
        cout << "La liste adjacente est vide.\n" << endl;
    }
    else
    {
        cout << "id\t" << endl;
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
