#include "libs.h"
#include "MatrixI.h"
#include "List.h"
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"
#include "Heap.h"

int main(int argc, char **argv)
{
	cout << "---- Welcome to Graph ----" << endl;

	Graph* graph = new Graph();
	graph->file2graph();
    /* construction du graph à partir du fichier graph_file.txt */
    /* graph->display(); */
	
	delete graph;
	return 0;
}

