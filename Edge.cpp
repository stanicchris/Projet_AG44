#include "Edge.h"

Edge::Edge() {}

Edge::~Edge() {}

Edge::Edge(Vertex* v0,Vertex* v1, unsigned int _id, unsigned int _type) {
	if (_type == 0) { /* oriente */
		type = _type;
		id = _id;
		vertex.push_back(v0);
		vertex.push_back(v1);
	}
	else if (_type == 1) { /* non oriente */
		type = _type;
		id = _id;
		src = v0;
		dest = v1;
	}
	else { cout << "Erreur dans la creation du edge n°" << _id << endl; }
}

void Edge::set_v0(Vertex* v0) {
	vertex.clear();
	vertex.push_back(v0);
}

void Edge::set_v1(Vertex* v1) { vertex.push_back(v1); }
