#include "libs.h"
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

int main(int argc, char **argv)
{
	cout << endl;
	cout << "---- Welcome to Graph ----" << endl << endl;
	Graph* graph = new Graph();
	graph->file2graph();
	graph->display();

/*
	// EXEMPLE 1
	graph->dfs(NULL);
	graph->print_dfs_list();
	if (graph->graph_connexe()) {
		cout << "le graphe est connexe" << endl;
	}
	else {
		cout << "le graphe n'est pas connexe" << endl;
	}
*/

/*
	// EXEMPLE 2
	ofstream out("source/graph_output.txt");
	streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
	if (graph->get_type() == 0) {
		//ofstream out1("source/kruskal_output.txt");
		ofstream out1("kruskal_output.txt");
		cout.rdbuf(out1.rdbuf()); //redirect std::cout to out.txt!

		int mst_wt = graph->kruskalMST();
		cout << "\nWeight of MST is " << mst_wt << "\n";

		//ofstream out2("source/prim_output.txt");
		ofstream out2("prim_output.txt");
		std::cout.rdbuf(out2.rdbuf()); //redirect std::cout to out.txt!

		mst_wt = graph->primMST();
		cout << "\nWeight of MST is " << mst_wt << "\n";
	}
	std::cout.rdbuf(coutbuf); //reset to standard output again
*/
	delete graph;
	cout << endl;
	system("pause");
	return 0;
}
