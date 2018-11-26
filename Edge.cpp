#include "Edge.h"

Edge::Edge() {}

Edge::~Edge() {
	if (src != NULL || dest != NULL) { cout << "Suppression d'un edge et de ses pointeurs NON-NULL !" << endl; }
    delete src;
    delete dest;
}

Edge::Edge(Vertex* v0,Vertex* v1, unsigned int _id, unsigned int _type) {
	if (_type == 1) { /* oriente */
		type = _type;
		id = _id;
		vertex.push_back(v0);
		vertex.push_back(v1);
	}
	else if (_type == 0) { /* non oriente */
		type = _type;
		id = _id;
		src = v0;
		dest = v1;
	}
	else { cout << "Erreur dans la creation du edge n°" << _id << endl; }
}

int Edge::is_n_edge(Vertex* v1, Vertex* v2) {
	if((vertex[0]==v1 && vertex[1] == v2) || (vertex[0] == v2 && vertex[1] == v1)) {return 1;}
	else { return 0; }
}

int Edge::is_o_edge(Vertex* source, Vertex* destination) {
	if (src == source && dest == destination) { return 1; }
	else { return 0; }
}

void Edge::set_v0(Vertex* v0) {
	vertex.clear();
	vertex.push_back(v0);
}

void Edge::set_v1(Vertex* v1) { vertex.push_back(v1); }