#include "Graph.h"

Graph::Graph() {
	sizeV = 0;
	sizeE=0;
}

Graph::~Graph() {
	for (unsigned int i = 0; i < listVertex.size(); i++) { delete listVertex[i]; }
	for (unsigned int i = 0; i < listEdge.size(); i++) { delete listEdge[i]; }
}

void Graph::create_n_edge(Vertex* v1, Vertex* v2) {
	listEdge.push_back(new Edge(v1, v2, listEdge.size()+1, 0));
}

void Graph::create_o_edge(Vertex* src, Vertex* dest) {
	listEdge.push_back(new Edge(src, dest, listEdge.size() + 1, 1));
}

void Graph::file2graph() {
	ifstream infile;
	infile.open("graph_file.txt"); /* change the path if necessary */
	//infile.open("source/graph_file.txt");
	if (infile.fail()) {
		infile.open("source/graph_file.txt");
		if (infile.fail()) {
			cout << "Ouverture du fichier graph_file.txt echouee !" << endl;
			system("pause");
			exit(1);
		}
	}
	char c;
	infile >> sizeV;
	if (sizeV > 0) { /* build the list */
		for(unsigned int i=0; i<sizeV; i++) {
			listVertex.push_back(new Vertex(0,0,i+1));
		}
		/*cout << _getcwd(NULL,0) << endl; display the current repositery */
		infile >> c;
		if (c == 'o') { //oriented graph
			type = 1;
			infile >> c;
			if (c == 'l') { //adjacency list
				adj = 1;
				cout << "graphe oriente avec liste adjacence" << endl;
				graph_o_list(infile);
			}
			else if (c == 'm') {//adjacency matrix
				adj = 0;
				cout << "graphe oriente avec matrice adjacence" << endl;
				graph_o_matrix(infile);
			}
			else { cout << "Erreur dans le type d'adjacence du graphe dans le fichier txt" << endl; }
		}
		else if (c == 'n') {
			type = 0;
			infile >> c;
			if (c == 'l') {
				adj = 1;
				cout << "graphe non oriente avec liste adjacence" << endl;
				graph_n_list(infile);
			}
			else if (c == 'm') {
				adj = 0;
				cout << "graphe non oriente avec matrice adjacence" << endl;
				graph_n_matrix(infile);
			}
			else { cout << "Erreur dans le type d'adjacence du graphe dans le fichier txt" << endl; }
		}
		else { cout << "Erreur dans le type de graphe dans le ichier txt" << endl; }
	}
	else { cout << "taille du graphe infereieur ou egale a 0" << endl; }
	infile.close();
}

void Graph::graph_o_matrix(ifstream& infile) {
	vector<unsigned int> temp;
	int val;
	for (unsigned int i = 0; i<sizeV; i++) {
		adjmatrix.push_back(temp);
		for (unsigned int j = 0; j<sizeV; j++) {//save the vertices with which he has an edge
			infile >> val;
			adjmatrix[i].push_back(val);
			if (adjmatrix[i][j] == 1) { //check if the vertices i and j are linked by an edge
				create_o_edge(listVertex[i], listVertex[j]); //create an edge for these vertices
			}
		}
	}
}

void Graph::graph_n_matrix(ifstream& infile) {
	vector<unsigned int> temp;
	int val;
	for (unsigned int i = 0; i<sizeV; i++) {
		adjmatrix.push_back(temp);
		for (unsigned int j = 0; j<i+1; j++) {
			infile >> val;
			adjmatrix[i].push_back(val);
			if (adjmatrix[i][j] == 1) { create_n_edge(listVertex[i], listVertex[j]); }
		}
	}
}

void Graph::graph_o_list(ifstream& infile) {
	unsigned int i;
	vector<Vertex*> temp;
	for (unsigned int j = 0; j < sizeV; j++) {
		adjlist.push_back(temp);
		infile >> i;
		while (i != 0) {
			adjlist[j].push_back(listVertex[i-1]);
			create_o_edge(listVertex[j], listVertex[i-1]);
			infile >> i;
		}
	}
}

void Graph::graph_n_list(ifstream& infile) {
	unsigned int i;
	vector<Vertex*> temp;
	for (unsigned int j = 0; j < sizeV; j++) {
		adjlist.push_back(temp);
		infile >> i;
		while (i != 0) {
			adjlist[j].push_back(listVertex[i-1]);
			create_n_edge(listVertex[j], listVertex[i-1]);
			infile >> i;
		}
	}
}

void Graph::display() {
	if (type == 1) { display_o(); }
	else if (type == 0) { display_n(); }
	else { cout << "Le type du graphe n'est pas defini !" << endl; }
}

void Graph::display_n() {
	cout << "vertex : ";
    for(unsigned int i=0; i<listVertex.size(); i++) { //display all the vertices
        cout << listVertex[i]->getID() << " ";
    }
	cout << endl << "edge :" << endl;
	for (unsigned int i = 0; i<listEdge.size(); i++) { //display all the edges with their vertices
		cout << listEdge[i]->getID() << " : " << listEdge[i]->getPoids() << " : " << 
			listEdge[i]->get_ID_v0() << " et " << listEdge[i]->get_ID_v1() << endl;
	}
}

void Graph::display_o() {
	cout << "vertex :" << endl;
	for (unsigned int i = 0;i < listVertex.size();i++) {
		cout << listVertex[i]->getID() << endl;
	}
	cout << endl << "edge :" << endl;
	for (unsigned int i = 0;i < listEdge.size(); i++) {
		cout << listEdge[i]->getID() << " : " << listEdge[i]->getPoids() << " : " << 
			listEdge[i]->get_ID_Src() << " vers " << listEdge[i]->get_ID_Dest() << endl;
	}
}

void Graph::deleteVertex(unsigned int id) {
	if (id <= listVertex.size()) {
		unsigned int increment=0;
		Vertex* temp = listVertex[id - 1];
		vector<Edge*> edge; //to save all the edges before delete them
		while(increment<listEdge.size()) { //travers the list of the edge to find which edge he is part of to delete them
			if (listEdge[increment]->getSrc() == temp || listEdge[increment]->getDest() == temp || 
					listEdge[increment]->get_v0() == temp || listEdge[increment]->get_v1() == temp) {
				edge.push_back(listEdge[increment]); //save the edge to delete it
				listEdge.erase(listEdge.begin() + increment);
				sizeE--;
			}
			else { increment++; }
		}
		if (adj == 1) {//adjacency list
			for (unsigned int i = 0; i < adjlist.size(); i++) {//search the line of the vertex in the adjacency list to delete it
				if(i==(temp->getID()-1)){adjlist.erase(adjlist.begin()+i); } //delete the vertex if it's him
				else {
					for (unsigned int j = 0; j < adjlist[i].size(); j++) {//check if the vertex is not linked with this one
						if (adjlist[i][j] == temp) { adjlist[i].erase(adjlist[i].begin()+j);}// delete it
					}
				}
			}
		}
		else {//adjacency matrix
			adjmatrix.erase(adjmatrix.begin() + id-1); // delete the line of the matrix corresponding to the vertex to delete
			for (unsigned int i = 0; i < adjmatrix.size(); i++) { //delete the column of the matrix corresponding to the vertex to delete
				adjmatrix[i].erase(adjmatrix[i].begin() + id-1);
			}
		}
		listVertex.erase(listVertex.begin() + (id - 1));// delete the vertex grom the list of vertex of the graph
		for (unsigned int i = 0; i < listVertex.size(); i++) {//correct the ID of the vertices of the graph
			listVertex[i]->setID(i+1);
		}
		for (unsigned int i = 0; i < listEdge.size(); i++) {//correct the ID of the edges of the graph
			listEdge[i]->setID(i + 1);
		}
		for (unsigned int i = 0; i < edge.size(); i++) {//delete all the edge the vertex was part of
			delete edge[i];
			sizeE--;
		}
		delete temp; //deallocate the space memory allocated for the edge
		sizeV--;
	}
	else { cout << "La liste de vertex ne contient pas le vertex n°" << id << endl; }
}

void Graph::deleteEdge(unsigned int id) {
	if (id <= listEdge.size()) {
		Edge* temp = listEdge[id - 1];
		if (type == 1) { //oriented
			if (adj == 1) { //list
				unsigned int i = (listEdge[id - 1]->get_ID_Src())-1;//get the ID of the vertex source of the edge
				//search the destination vertex of the edge in the adjacency list's row associates to the source vertex
				for (unsigned int j = 0; j < adjlist[i].size(); j++) {
					//check if it's him, delete it
					if (listEdge[id - 1]->get_ID_Dest() == adjlist[i][j]->getID()) { adjlist[i].erase(adjlist[i].begin() + j); }
				}
			}
			else { //matrix
				//put 0 in the mattrix cell associates to the edge
				unsigned int i = listEdge[id - 1]->get_ID_Src();
				unsigned int j = listEdge[id - 1]->get_ID_Dest();
				adjmatrix[i-1][j-1] = 0;
			}
		}
		else {//non-oriented
			if (adj == 1) {
				unsigned int i = listEdge[id - 1]->get_ID_v0() - 1;
				for (unsigned int j = 0; j < adjlist[i].size(); j++) {
					if (listEdge[id - 1]->get_ID_v1() == adjlist[i][j]->getID()) { adjlist[i].erase(adjlist[i].begin() + j); }
				}
				i = listEdge[id - 1]->get_ID_v1() - 1;
				for (unsigned int j = 0; j < adjlist[i].size(); j++) {
					if (listEdge[id - 1]->get_ID_v0() == adjlist[i][j]->getID()) {  adjlist[i].erase(adjlist[i].begin() + j); }
				}
			}
			else { //matrice triangulaire
				unsigned int i = listEdge[id - 1]->get_ID_v0();
				unsigned int j = listEdge[id - 1]->get_ID_v1();
				if(i>j) { adjmatrix[i - 1][j - 1] = 0; }
				else { adjmatrix[j - 1][i - 1] = 0; }
			}
		}
		listEdge.erase(listEdge.begin() + (id - 1)); //remove the edge frome the list of edge of the graph
		for (unsigned int i = 0; i < listEdge.size(); i++) {
			listEdge[i]->setID(i + 1);
		}
		delete temp; //deallocate the space memory allocated for the edge
		sizeE--;
	}
	else { cout << "La liste de edge ne contient pas l'edge n°"<< id << endl; }
}

void Graph::o_matrix2list() {
	vector<Vertex*> v;
	for(unsigned int i=0; i<sizeV; i++) {
		adjlist.push_back(v);
		for (unsigned int j=0; j<sizeV; j++) { //build an adjacency list from the adjacency matrix
			if(adjmatrix[i][j]==1) {
				adjlist[i].push_back(listVertex[j]);
			}
		}
	}
}

void Graph::n_matrix2list() {
	vector<Vertex*> v;
	for(unsigned int i=0; i<sizeV; i++) { //build an adjacency list from the adjacency matrix
		adjlist.push_back(v);
		for (unsigned int j=0; j<i+1; j++) {
			if(adjmatrix[i][j]==1) {
				adjlist[i].push_back(listVertex[j]);
			}
		}
		for (unsigned int j=i; j<sizeV; j++) {
			if(adjmatrix[j][i]==1 && i!=j) {
				adjlist[i].push_back(listVertex[j]);
			}
		}
	}
}

void Graph::o_list2matrix() {
	vector<unsigned int> temp;
	for (unsigned int i = 0; i<sizeV; i++) { //build an adjacency matrix from the adjacency list
		adjmatrix.push_back(temp);
		for (unsigned int j = 0; j<sizeV; j++) {
			if(is_o_edge(listVertex[i],listVertex[j]) != NULL) {
				adjmatrix[i].push_back(1);
			}
			else { adjmatrix[i].push_back(0);}
		}
	}
}

void Graph::n_list2matrix() {
	vector<unsigned int> temp;
	for (unsigned int i = 0; i<sizeV; i++) { //build an adjacency matrix from the adjacency list
		adjmatrix.push_back(temp);
		for (unsigned int j = 0; j<i; j++) {
			if(is_n_edge(listVertex[i],listVertex[j]) != NULL) {
				adjmatrix[i].push_back(1);
			}
			else {adjmatrix[i].push_back(0);}
		}
	}
}

Edge* Graph::is_n_edge(Vertex* v0, Vertex* v1) {
	for(unsigned int i=0; i<listEdge.size(); i++) { //travers the list of edge of the graph to find it
		if(listEdge[i]->get_v0()==v0 && listEdge[i]->get_v1()==v1) { //check if it's him
			return listEdge[i];
		}
		if(listEdge[i]->get_v0()==v1 && listEdge[i]->get_v1()==v0) { //check if it's him
			return listEdge[i];
		}
	}
	return NULL;
}

Edge* Graph::is_o_edge(Vertex* source, Vertex* destination) {
	for(unsigned int i=0; i<listEdge.size(); i++) { //travers the list of edge to find it
		if(listEdge[i]->getSrc()==source && listEdge[i]->getDest()==destination) {
			return listEdge[i];
		}
	}
	return NULL;
}

int Graph::graph_connexe() {
	//check the type of adjacency to choose wich function to use
	return 0;
}

int Graph::pathes_list_prefixe() {
	if (listVertex.size() > 0) {
		srand(time(0)); //initialise the random function
		unsigned int count = 1;
		Vertex* x = listVertex[rand()%listVertex.size()]; //choose a random vertex to begin
		x->setColor(GRAY); //initialize the vertex
		unsigned int i = 0;
		while (adjlist[x->getID() + 1][i]->getColor() != WHITE) { i++; }

		//searching.....

		return count;
	}
	else { return 0; }
}

int Graph::pathes_matrix_prefixe() {

	return 0;
}
