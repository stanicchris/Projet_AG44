#include "libs.h"
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

int main(int argc, char **argv)
{

	ofstream out("source/graph_output.txt");
	streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	cout << "---- Welcome to Graph ----" << endl << endl;
	Graph* graph = new Graph();

	graph->file2graph();
	graph->display();


	if (graph->get_type() == 0) {
		ofstream out1("source/kruskal_output.txt");
		cout.rdbuf(out1.rdbuf()); //redirect std::cout to out.txt!

		int mst_wt = graph->kruskalMST();
		cout << "\nWeight of MST is " << mst_wt << "\n";

		ofstream out2("source/prim_output.txt");
		std::cout.rdbuf(out2.rdbuf()); //redirect std::cout to out.txt!

		mst_wt = graph->primMST();
		cout << "\nWeight of MST is " << mst_wt << "\n";
	}
	

	delete graph;
	std::cout.rdbuf(coutbuf); //reset to standard output again
	system("pause");
	return 0;
}
