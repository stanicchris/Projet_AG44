#include "Edge.h"

Edge::Edge() {}

Edge::~Edge() {}

Edge::Edge(Vertex* v0,Vertex* v1, unsigned int _id, unsigned int _type, unsigned int _poids) {
	if (_type == 0) { /* oriented */
		type = _type;
		id = _id;
		vertex.push_back(v0);
		vertex.push_back(v1);
		poids = rand() % 10 + 1;
	}
	else if (_type == 1) { /* non oriented */
		type = _type;
		id = _id;
		src = v0;
		dest = v1;
		poids = rand() % 10 + 1;
	}
	else { cout << "Erreur dans la creation du edge n°" << _id << endl; }
	poids = _poids;
}

void Edge::set_v0(Vertex* v0) {
	vertex.clear();
	vertex.push_back(v0);
}

void Edge::set_v1(Vertex* v1) { vertex.push_back(v1); }
