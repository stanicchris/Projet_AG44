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
	ifstream infile;

	graph->file2graph();
	graph->display();
	graph->deleteEdge(3);
	graph->display();

	delete graph;
	system("pause");
	return 0;
}
