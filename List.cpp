#include "List.h"

List::List()
{
    vlist = NULL;
}

List::~List()
{
	delete vlist;
}

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
}
