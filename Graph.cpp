#include "Graph.h"

Graph::Graph() {
	adjmatrix = NULL;
	sizeV = 0;
	sizeE=0;
}

Graph::~Graph() {
	for (unsigned int i = 0; i < listVertex.size(); i++) { delete listVertex[i]; }
	for (unsigned int i = 0; i < listEdge.size(); i++) { delete listEdge[i]; }
	for (unsigned int i = 0; i <sizeV; i++){delete adjmatrix[i];}
	delete adjmatrix;
}

void Graph::create_n_edge(Vertex* v1, Vertex* v2) {
	listEdge.push_back(new Edge(v1, v2, listEdge.size()+1, 0));
}

void Graph::create_o_edge(Vertex* src, Vertex* dest) {
	listEdge.push_back(new Edge(src, dest, listEdge.size() + 1, 1));
}

void Graph::file2graph() {
	ifstream infile;
	infile.open("graph_file.txt"); /* changer le chemin si necessaire */
	if (infile.fail()) { cout << "Ouverture du fichier graph_file.txt echouee !" << endl; }
	else {
		char c;
		infile >> sizeV;
		if (sizeV > 0) { /* construit la liste */
		for(unsigned int i=0; i<sizeV; i++) {
			listVertex.push_back(new Vertex(0,0,i+1));
		}
			/*cout << _getcwd(NULL,0) << endl; afficher le repertoire courant */
			infile >> c;
			if (c == 'o') {
				type = 1;
				infile >> c;
				if (c == 'l') {
					adj = 1;
					cout << "graphe oriente avec liste adjacence" << endl;
					graph_o_list(infile);
				}
				else if (c == 'm') {
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
	}
	infile.close();
}

void Graph::graph_o_matrix(ifstream& infile) {
	adjmatrix = new unsigned int*[sizeV];
	for (unsigned int i = 0; i<sizeV; i++) {
		adjmatrix[i] = new unsigned int[sizeV];
		for (unsigned int j = 0; j<sizeV; j++) {
			infile >> adjmatrix[i][j];
			if (adjmatrix[i][j] == 1) { create_o_edge(listVertex[i], listVertex[j]); }
		}
	}
}

void Graph::graph_n_matrix(ifstream& infile) {
	adjmatrix = new unsigned int* [sizeV];
	for (unsigned int i = 0; i<sizeV; i++) {
		adjmatrix[i] = new unsigned int [sizeV];
		for (unsigned int j = 0; j<i+1; j++) {
			infile >> adjmatrix[i][j];
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
			adjlist[j].push_back(listVertex[i]);
			if (i != 0) { create_o_edge(listVertex[j], listVertex[i-1]); }
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
			adjlist[j].push_back(listVertex[i]);
			if (i != 0) { create_n_edge(listVertex[j], listVertex[i-1]); }
			infile >> i;
		}
	}
}

void Graph::display() {
	if (type == 1) { display_o(); }
	else if (type == 0) { display_n(); }
	else { cout << "Le type du graphe n'est pas defini !" << endl; }
}

void Graph::display_o() {
	cout << "vertex : ";
    for(unsigned int i=0; i<listVertex.size(); i++) {
        cout << listVertex[i]->getID() << " ";
    }
	cout << endl << "edge :" << endl;
	for (unsigned int i = 0; i<listEdge.size(); i++) {
		cout << listEdge[i]->getID() << " de " << listEdge[i]->get_ID_v0() << " vers " << listEdge[i]->get_ID_v1() << endl;
	}
}

void Graph::display_n() {
	cout << "vertex :" << endl;
	for (unsigned int i = 0;i < listVertex.size();i++) {
		cout << listVertex[i]->getID() << endl;
	}
	cout << endl << "edge :" << endl;
	for (unsigned int i = 0;i < listEdge.size(); i++) {
		cout << listEdge[i]->getID() << " " << listEdge[i]->get_ID_Src() << " et " << listEdge[i]->get_ID_Dest() << endl;
	}
}

void Graph::deleteVertex(unsigned int id) {
	if (id <= listVertex.size()) {
		Vertex* temp = listVertex[id - 1];
		listVertex.erase(listVertex.begin() + (id - 1));
		for (unsigned int i = 0; i < listVertex.size(); i++) {
			listVertex[i]->setID(i + 1);
		}
		delete temp;
		sizeV--;
	}
	else { cout << "La liste de vertex ne contient pas le vertex n°" << id << endl; }
}

void Graph::deleteEdge(unsigned int id) {
	if (id <= listEdge.size()) {
		Edge* temp = listEdge[id - 1];
		listEdge.erase(listEdge.begin()+ (id-1));
		for (unsigned int i = 0; i < listEdge.size(); i++) {
			listEdge[i]->setID(i + 1);
		}
		delete temp;
		sizeE--;
	}
	else { cout << "La liste de edge ne contient pas l'edge n°"<< id << endl; }
}

void Graph::o_matrix2list() {
	vector<Vertex*> v;
	for(unsigned int i=0; i<sizeV; i++) {
		adjlist.push_back(v);
		for (unsigned int j=0; j<sizeV; j++) {
			if(adjmatrix[i][j]==1) {
				adjlist[i].push_back(listVertex[j]);
			}
		}
	}
}

void Graph::n_matrix2list() {
	vector<Vertex*> v;
	for(unsigned int i=0; i<sizeV; i++) {
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
	delete adjmatrix;
	adjmatrix = new unsigned int*[sizeV];
	for (unsigned int i = 0; i<sizeV; i++) {
		adjmatrix[i] = new unsigned int[sizeV];
		for (unsigned int j = 0; j<sizeV; j++) {
			if(is_o_edge(listVertex[i],listVertex[j]) != NULL) {
				adjmatrix[i][j] = 1;
			}
			else {adjmatrix[i][j] = 0;}
		}
	}
}

void Graph::n_list2matrix() {
	delete adjmatrix;
	adjmatrix = new unsigned int*[sizeV];
	for (unsigned int i = 0; i<sizeV; i++) {
		adjmatrix[i] = new unsigned int[sizeV];
		for (unsigned int j = 0; j<i; j++) {
			if(is_n_edge(listVertex[i],listVertex[j]) != NULL) {
				adjmatrix[i][j] = 1;
			}
			else {adjmatrix[i][j] = 0;}
		}
	}
}

Edge* Graph::is_n_edge(Vertex* v0, Vertex* v1) {
	for(unsigned int i=0; i<listEdge.size(); i++) {
		if(listEdge[i]->get_v0()==v0 && listEdge[i]->get_v1()==v1) {
			return listEdge[i];
		}
		if(listEdge[i]->get_v0()==v1 && listEdge[i]->get_v1()==v0) {
			return listEdge[i];
		}
	}
	return NULL;
}

Edge* Graph::is_o_edge(Vertex* source, Vertex* destination) {
	for(unsigned int i=0; i<listEdge.size(); i++) {
		if(listEdge[i]->getSrc()==source && listEdge[i]->getDest()==destination) {
			return listEdge[i];
		}
	}
	return NULL;
}
