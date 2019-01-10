#include "libs.h"
#include "MatrixI.h"
#include "List.h"
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"
#include "Heap.h"

int main(int argc, char **argv)
{
	cout << "---- Welcome to Graph ----" << endl << endl;
	Graph* graph = new Graph();
	graph->file2graph();
	
	graph->dfs(NULL);
	graph->print_dfs_list();

	/*
	if (graph->graph_connexe()) {
		cout << "le graphe est connexe" << endl;
	}
	else {
		cout << "le graphe n'est pas connexe" << endl;
	}
	*/

	cout << endl << endl;
	delete graph;
	system("pause");
	return 0;
}
