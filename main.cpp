#include "libs.h"
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

int main(int argc, char **argv)
{

	std::ofstream out("source/output.txt");
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	cout << "---- Welcome to Graph ----" << endl << endl;
	Graph* graph = new Graph();

	graph->file2graph();
	graph->display();

	graph->display_edge();

	int mst_wt = graph->kruskalMST();
	cout << "\nWeight of MST is " << mst_wt << "\n";

	mst_wt = graph->primMST();
	cout << "\nWeight of MST is " << mst_wt << "\n";

	delete graph;
	std::cout.rdbuf(coutbuf); //reset to standard output again
	system("pause");
	return 0;
}
