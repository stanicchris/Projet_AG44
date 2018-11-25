#include "Graph.h"

Graph::Graph() {
	listEdge = NULL;
	listVertex = NULL;
	adjmatrix = NULL;
	sizeV = 0;
}

Graph::~Graph() {
	delete listEdge;
	delete listVertex;
	free(adjmatrix);
}

Vertex* Graph::vertex_id(int id) {
	if (id > sizeV) {
		cout << "Le vecteur n°" << id << " n'existe pas" << endl;
		return NULL;
	}
	else {
		Vertex* temp = listVertex;
		for (int i = 0; i < id; i++) { temp = temp->next(); }
		return temp;
	}
}

void Graph::file2graph() {
	ifstream infile;
	infile.open("source/graph_file.txt"); /* changer le chemin si necessaire */
	if (infile.fail()) { cout << "Ouverture du fichier graph_file.txt echouee !" << endl; }
	else {
		char c;
		infile >> this->sizeV;
		if (sizeV > 0) { /* construit la liste */
			Vertex* temp;
			listVertex = new Vertex(0, 0, 1);
			temp = listVertex;
			for (int i = 1; i < sizeV; i++) {
				temp->next(new Vertex(0, 0, i + 1));
				temp = temp->next();
			}
			/*cout << _getcwd(NULL,0) << endl; afficher le repertoire courant */
			infile >> c;
			if (c == 'o') {
				this->type = 1;
				infile >> c;
				if (c == 'l') {
					this->adj = 1;
					cout << "graphe oriente avec liste adjacence" << endl;
					graph_o_list(infile);
				}
				else if (c == 'm') {
					this->adj = 0;
					cout << "graphe oriente avec matrice adjacence" << endl;
					graph_o_matrix(infile);
				}
				else { cout << "Erreur dans le type d'adjacence du graphe dans le fichier txt" << endl; }
			}
			else if (c == 'n') {
				this->type = 0;
				infile >> c;
				if (c == 'l') {
					this->adj = 1;
					cout << "graphe non oriente avec liste adjacence" << endl;
					graph_n_list(infile);
				}
				else if (c == 'm') {
					this->adj = 0;
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
	this->adjmatrix = new int*[sizeV];
	for (int i = 0;i < this->sizeV;i++) {
		this->adjmatrix[i] = new int[sizeV];
		for (int j = 0;j < this->sizeV;j++) { infile >> this->adjmatrix[i][j]; }
	}
}

void Graph::graph_n_matrix(ifstream& infile) {
	this->adjmatrix = new int*[sizeV];
	for (int i = 0;i < this->sizeV;i++) {
		this->adjmatrix[i] = new int[sizeV];
		for (int j = 0;j < i;j++) { infile >> this->adjmatrix[i][j]; }
	}
}

void Graph::graph_o_list(ifstream& infile) {
	int i;
	vector<Vertex*> temp;
	for (int j = 0; j < this->sizeV; j++) {
		this->adjlist.push_back(temp);
		infile >> i;
		while (i != 0) {
			adjlist[j].push_back(vertex_id(i));
			infile >> i;
		}
	}
}

void Graph::graph_n_list(ifstream& infile) {

}

void Graph::display() {
	Vertex* temp = listVertex;
    for(int i=0;i<sizeV;i++) {
        cout << temp->getID() << endl;
        temp = temp->next();
    }
}

void Graph::ajouteVertex(Vertex* v) {
    if(sizeV == 0) {//yes
        listVertex=v;
    }
    else {
        Vertex* temp;
        int s=0;
        temp=listVertex;
        while(s<sizeV-1) {
            temp=temp->next();
            s++;
        }
        temp->next(v);
    }
    sizeV++;
}

void Graph::deleteVertex(int id) {
    if(sizeV<=0 || id<1 || id>sizeV) {
        cout << "La liste est vide ou il y a un probleme" << endl;
    }
    else if(sizeV==1) {
        Vertex* temp;
        temp = listVertex;
        listVertex = NULL;
        delete temp;
        sizeV--;
    }
    else if(id==1) {
        Vertex* temp;
        Vertex* temp1;
        temp = listVertex;
        listVertex = temp->next();
        temp->next(NULL);
        delete temp;
        int i=0;
        temp1 = listVertex;
        sizeV--;
        while(i<sizeV) {
            temp1->setID(temp1->getID()-1);
            temp1 = temp1->next();
            i++;
        }
    }
    else {
        Vertex* temp;
        Vertex* temp1;
        Vertex* temp2;
        int s1=0, s2=0;
        temp1=listVertex;
        temp2=listVertex;
        while(temp1->next()->getID()!= id)  {
            temp1=temp1->next();
            s1++;
        }
        while(s2<sizeV-2) {
            temp2=temp2->next();
            s2++;
        }
        temp=temp1->next();
        temp2->next()->setID(temp->getID());
        temp1->next(temp2->next());
        temp2->next(NULL);
        temp1->next()->next(temp->next());
        temp->next(NULL);
        delete temp;
        sizeV--;
    }
}

void Graph::ajouteEdge(Edge* e) {
    if(sizeE == 0) {
        listEdge=e;
    }
    else {
        Edge* temp;
        int s=0;
        temp=listEdge;
        while(s<sizeE-1) {
            temp=temp->next();
            s++;
        }
        temp->next(e);
    }
    sizeE++;
}

void Graph::deleteEdge(int id) {
    if(sizeE<=0 || id<1 || id>sizeE) {
        cout << "La liste est vide ou il y a un probleme" << endl;
    }
    else if(sizeE==1) {
        Edge* temp;
        temp = listEdge;
        listEdge = NULL;
        delete temp;
        sizeE--;
    }
    else if(id==1) {
        Edge* temp;
        Edge* temp1;
        temp = listEdge;
        listEdge = temp->next();
        temp->next(NULL);
        delete temp;
        int i=0;
        temp1 = listEdge;
        sizeE--;
        while(i<sizeE)
        {
            temp1->setID(temp1->getID()-1);
            temp1 = temp1->next();
            i++;
        }
    }
    else {
        Edge* temp;
        Edge* temp1;
        Edge* temp2;
        int s1=0, s2=0;
        temp1=listEdge;
        temp2=listEdge;
        while(temp1->next()->getID()!= id)  {
            temp1=temp1->next();
            s1++;
        }
        while(s2<sizeE-2) {
            temp2=temp2->next();
            s2++;
        }
        temp=temp1->next();
        temp2->next()->setID(temp->getID());
        temp1->next(temp2->next());
        temp2->next(NULL);
        temp1->next()->next(temp->next());
        temp->next(NULL);
        delete temp;
        sizeE--;
    }
}

Edge* Graph::voisins(Vertex* u,Vertex* v) {
    if(listEdge != NULL)  {
        Edge* temp = listEdge;
        if((temp->getDest() == v && temp->getSrc() == u) || (temp->getDest() == u && temp->getSrc() == v))  { return temp; }
        else {
            while(temp->next() != NULL)  {
                if((temp->getDest() == v && temp->getSrc() == u) || (temp->getDest() == u && temp->getSrc() == v)) { return temp; }
                else {temp=temp->next();}
            }
        }
        if((temp->getDest() == v && temp->getSrc() == u) || (temp->getDest() == u && temp->getSrc() == v)) { return temp; }
        else { return NULL; }
    }
    else { return NULL; }
}

