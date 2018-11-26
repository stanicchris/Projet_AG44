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
	//graph->file2graph();
	//graph->display();
	ifstream infile;
	infile.open("source/graph_file.txt");
	int i;
	//tester si le chemin fonction

	infile.close();
	delete graph;
	system("pause"); /*permet de voir le terminal */
	return 0;
}
