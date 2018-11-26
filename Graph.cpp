#include "Graph.h"

Graph::Graph() {
	adjmatrix = NULL;
	sizeV = 0;
}

Graph::~Graph() {
	for (unsigned int i = 0; i < listVertex.size(); i++) { delete listVertex[i]; }
	for (unsigned int i = 0; i < listEdge.size(); i++) { delete listEdge[i]; }
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
	infile.open("source/graph_file.txt"); /* changer le chemin si necessaire */
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
		for (unsigned int j = 0; j<i; j++) {
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
			infile >> i;
			if (i != 0) { create_o_edge(listVertex[j + 1], listVertex[i]); }
		}
	}
}

void Graph::graph_n_list(ifstream& infile) {
	unsigned int i;
	vector<Vertex*> temp;
	for (unsigned int j = 0; j < this->sizeV; j++) {
		adjlist.push_back(temp);
		infile >> i;
		while (i != 0) {
			adjlist[j].push_back(listVertex[i]);
			infile >> i;
			if (i != 0) { create_n_edge(listVertex[j+1], listVertex[i]); }
		}
	}
}

void Graph::display() {
	if (type == 1) { display_o(); }
	else if (type == 0) { display_n(); }
	else { cout << "Le type du graphe n'est pas defini !" << endl; }
}

void Graph::display_o() {
	cout << "vertex :" << endl;
    for(unsigned int i=0; i<listVertex.size(); i++) {
        cout << listVertex[i]->getID() << endl;
    }
	cout << endl << "edge :" << endl;
	for (unsigned int i = 0; i<listEdge.size(); i++) {
		cout << listEdge[i]->getID() << " de " << listEdge[i]->getSrc()->getID() << " vers " << listEdge[i]->getDest()->getID() << endl;
	}
}

void Graph::display_n() {
	cout << "vertex :" << endl;
	for (unsigned int i = 0;i < listVertex.size();i++) {
		cout << listVertex[i]->getID() << endl;
	}
	cout << endl << "edge :" << endl;
	for (unsigned int i = 0;i < listEdge.size(); i++) {
		cout << listEdge[i]->getID() << " " << listEdge[i]->get_v0()->getID() << " et " << listEdge[i]->get_v1()->getID() << endl;
	}
}

void Graph::ajouteVertex(Vertex* v) {listVertex.push_back(v);}

void Graph::deleteVertex(unsigned int id) {
    /*if(sizeV<=0 || id<1 || id>sizeV) {cout << "La liste de vertex est vide ou il y a un probleme" << endl;}
    else if(id==1 && sizeV==1) {
		delete listVertex;
        sizeV--;
    }
    else if(id==1) {
        Vertex* temp;
        temp = listVertex;
        listVertex = temp->next();
        temp->next(NULL);
        delete temp;
        int i=0;
        temp = listVertex;
        sizeV--;
        while(i<sizeV) {
            temp->setID(temp->getID()-1);
            temp = temp->next();
            i++;
        }
    }
    else {
        Vertex* temp;
        Vertex* temp1;
        temp1=listVertex;
        while(temp1->getID() < id-1) {temp1 = temp1->next();}
        temp = temp1->next();
		temp1->next(temp->next());
		temp->next(NULL);
		delete temp;
		temp = temp1->next();
		while (temp != NULL) {
			temp->setID(temp->getID() - 1);
			temp = temp->next();
		}
        sizeV--;*/
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

void Graph::ajouteEdge(Edge* e) {listEdge.push_back(e);}

void Graph::deleteEdge(unsigned int id) {
    /*if(sizeE <= 0 || id<1 || id>sizeE) {cout << "La liste de edge est vide ou il y a un probleme" << endl;}
    else if(sizeE==1) {
        delete listEdge;
        sizeE--;
    }
    else if(id==1) {
        Edge* temp;
        temp = listEdge;
        listEdge = temp->next();
        temp->next(NULL);
        delete temp;
        temp = listEdge;
        while(temp->next()!=NULL) {
            temp->setID(temp->getID()-1);
            temp = temp->next();
        }
		sizeE--;
    }
    else {
        Edge* temp;
        Edge* temp1;
        temp1=listEdge;
        while(temp1->getID() < id-1)  { temp1=temp1->next();}
        temp=temp1->next();
		temp1->next(temp->next());
		temp->next(NULL);
        delete temp;
		temp = temp1->next();
		while(temp != NULL) {
			temp->setID(temp->getID() - 1);
			temp = temp->next();
		}
        sizeE--;
    }*/
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

Edge* Graph::voisin_o(Vertex* source,Vertex* destination) {
	for (unsigned int i = 0; i < listEdge.size(); i++) {
		if (listEdge[i]->is_o_edge(source,destination))
			{ return listEdge[i]; }
	}
	return NULL;
}

Edge* Graph::voisin_n(Vertex* v1, Vertex* v2) {
	for (unsigned int i = 0; i < listEdge.size(); i++) {
		if (listEdge[i]->is_n_edge(v1,v2))
			{ return listEdge[i]; }
	}
	return NULL;
}
