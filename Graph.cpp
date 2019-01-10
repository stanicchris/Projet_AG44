#include "Graph.h"

Graph::Graph() {
	sizeV = 0;
	sizeE=0;
}

Graph::~Graph() {
	for (unsigned int i = 0; i < listVertex.size(); i++) { delete listVertex[i]; }
	for (unsigned int i = 0; i < listEdge.size(); i++) { delete listEdge[i]; }
}

void Graph::create_n_edge(Vertex* v1, Vertex* v2, unsigned int _poids) {
	listEdge.push_back(new Edge(v1, v2, listEdge.size() + 1, 0, _poids));
}

void Graph::create_o_edge(Vertex* src, Vertex* dest, unsigned int _poids) {
	listEdge.push_back(new Edge(src, dest, listEdge.size() + 1, 1, _poids));
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
		/* cout << _getcwd(NULL,0) << endl; display the current repositery */
		infile >> c;
		if (c == 'o') { // oriented graph
			type = 1;
			infile >> c;
			if (c == 'l') { // adjacency list
				adj = 1;
				cout << "graphe oriente avec liste adjacence" << endl;
				graph_o_list(infile);
			}
			else if (c == 'm') { // adjacency matrix
				adj = 0;
				cout << "graphe oriente avec matrice adjacence" << endl;
				graph_o_matrix(infile);
			}
			else { cout << "Erreur dans le type d'adjacence du graphe dans le fichier txt" << endl; }
		}
		else if (c == 'n') { // non-oriented graph
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
	if (!infile.eof()) {
		cout << "le fichier contient d'autres elements" << endl;
	}
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
			if (adjmatrix[i][j] >= 1) { //check if the vertices i and j are linked by an edge
				create_o_edge(listVertex[i], listVertex[j], val); //create an edge for these vertices
			}
		}
	}
}

void Graph::graph_n_matrix(ifstream& infile) {
	vector<unsigned int> temp;
	unsigned int val;
	for (unsigned int i = 0; i<sizeV; i++) {
		adjmatrix.push_back(temp);
		for (unsigned int j = 0; j<i+1; j++) {
			infile >> val;
			adjmatrix[i].push_back(val);
			if (adjmatrix[i][j] >= 1) { 
				create_n_edge(listVertex[j], listVertex[i], val); 
				create_n_edge(listVertex[i], listVertex[j], val);
			}
		}
	}
}

void Graph::graph_o_list(ifstream& infile) {
	unsigned int i;
	unsigned int i_temp;
	vector<Vertex*> temp;
	for (unsigned int j = 0; j < sizeV; j++) {
		adjlist.push_back(temp);
		infile >> i;
		while (i != 0) {
			adjlist[j].push_back(listVertex[i - 1]);
			i_temp = i;
			infile >> i;
			if (i_temp != 0) { create_o_edge(listVertex[j], listVertex[i_temp -1], i); }
			infile >> i;
		}
	}
}

void Graph::graph_n_list(ifstream& infile) {
	unsigned int i;
	unsigned int i_temp;
	vector<Vertex*> temp;
	for (unsigned int j = 0; j < sizeV; j++) {
		adjlist.push_back(temp);
		infile >> i;
		while (i != 0) {
			adjlist[j].push_back(listVertex[i - 1]);
			i_temp = i;
			infile >> i;
			if (i_temp != 0) { create_n_edge(listVertex[j], listVertex[i_temp - 1], i); }
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
	/*cout << endl << "edge :" << endl;
	for (unsigned int i = 0; i<listEdge.size(); i++) {
		cout << listEdge[i]->getID() << ": de " << listEdge[i]->get_ID_v0() << " vers " << listEdge[i]->get_ID_v1() << endl;
	}*/
	display_edge();
}

void Graph::display_o() {
	cout << "vertex : ";
	for (unsigned int i = 0;i < listVertex.size();i++) {
		cout << listVertex[i]->getID() << " ";
	}
	/*cout << endl << "edge :" << endl;
	for (unsigned int i = 0;i < listEdge.size(); i++) 
		cout << listEdge[i]->getID() << ": " << listEdge[i]->get_ID_Src() << " vers " << listEdge[i]->get_ID_Dest() << endl;
	}*/
	display_edge();
}

void Graph::display_edge() {

	cout << endl << "\nAffichage des edges et de leurs poids : \n" << endl;
	if (type == 1) {
		for (unsigned int i = 0; i<listEdge.size(); i++) {
			cout << "De " << listEdge[i]->get_ID_Src() << " vers " << listEdge[i]->get_ID_Dest() << " avec un poids de : " << listEdge[i]->getPoids() << endl;
		}
	}
	else {
		for (unsigned int i = 0; i<listEdge.size(); i++) {
			cout << "De " << listEdge[i]->get_ID_v0() << " vers " << listEdge[i]->get_ID_v1() << " avec un poids de : " << listEdge[i]->getPoids() << endl;
		}
	}
	cout << endl;
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

unsigned int Graph::graph_connexe() {
	if (type == 0) {
		//check the type of adjacency to choose wich function to use
		unsigned int count = 0;
		if (this->adj == 1) {
			count = pathes_list_prefixe(0);
		}
		else {
			count = pathes_matrix_prefixe(0);
		}
		return (count == listVertex.size());
	}
	else {
		cout << "Le graphe n'est pas non-oriente, ne peut pas appliquer la fonction graph_connexe" << endl;
		return 0;
	}
}

unsigned int Graph::pathes_list_prefixe(unsigned int index) {
	if (listVertex.size() > 0) {
		unsigned int count = 1;
		listVertex[index]->setColor(GRAY); //initialize the vertex
		for (unsigned int i = 0; i < adjlist[index].size(); i++) {
			if (adjlist[index][i]->getColor() == WHITE) {
				count += pathes_list_prefixe(adjlist[index][i]->getID() - 1);
			}
		}
		listVertex[index]->setColor(BLACK);
		return count;
	}
	else { return 0; }
}

unsigned int Graph::pathes_matrix_prefixe(unsigned int index) {
	if (listVertex.size() > 0) {
		unsigned int count = 1;
		listVertex[index]->setColor(GRAY); //initialize the vertex
		for (unsigned int i = 0; i <= index; i++) {
			if ((adjmatrix[index][i] == 1) && (listVertex[i]->getColor() == WHITE)) {
				count += pathes_matrix_prefixe(i);
			}
		}
		for (unsigned int i = index; i < 5; i++) {
			if ((adjmatrix[i][index] == 1) && (listVertex[i]->getColor() == WHITE)) {
				count += pathes_matrix_prefixe(i);
			}
		}
		listVertex[index]->setColor(BLACK);
		return count;
	}
	else { return 0; }
}

void Graph::dfs(Vertex* source) {
	dfs_list.clear();
	unsigned int t = 0;
	unsigned int& time = t; //time is a reference which refers to t
	for (unsigned int i = 0; i < listVertex.size(); i++) { //initialisation of all verticies
		listVertex[i]->setColor(WHITE);
		listVertex[i]->tm[0] = 0;
		listVertex[i]->tm[1] = 0;
	}
	if (source == NULL) {
		dfs_visit(listVertex[0], time);
	}
	else {
		dfs_visit(source, time); //we begin with the source
	}
	//if certain verticies are not accessible from source, we reach them here
	for (unsigned int i = 0; i < listVertex.size(); i++) {
		if (listVertex[i]->getColor() == WHITE) {
			dfs_visit(listVertex[i], time);
		}
	}
	/* save the sort list in file sort_file.txt */
	ofstream file;
	file.open("sort_file.txt");
	for (unsigned int i = 0; i < dfs_list.size(); i++) {
		file << dfs_list[i] << " : " << listVertex[dfs_list[i] - 1]->tm[0] << "," << listVertex[dfs_list[i] - 1]->tm[1] << "\n";
	}
	file.close();
}

void Graph::dfs_visit(Vertex* v, unsigned int& time) {
	time++;
	v->setColor(GRAY);
	v->tm[0] = time;
	if (adj == 1) {
		for (unsigned int i = 0; i < adjlist[v->getID()-1].size(); i++) {
			if (adjlist[v->getID() - 1][i]->getColor() == WHITE) {
				dfs_visit(adjlist[v->getID() - 1][i], time);
			}
		}
	}
	else {
		if (type == 1) {
			for (unsigned int i = 0; i < sizeV; i++) {
				if (adjmatrix[v->getID()-1][i] == 1 && listVertex[i]->getColor() == WHITE) {
					dfs_visit(listVertex[i], time);
				}
			}
		}
		else {
			for (unsigned int i = 0; i <= v->getID()-1; i++) {
				if (adjmatrix[v->getID() - 1][i] == 1 && listVertex[i]->getColor() == WHITE) {
					dfs_visit(listVertex[i], time);
				}
			}
			for (unsigned int i = v->getID()-1; i < sizeV; i++) {
				if (adjmatrix[i][v->getID() - 1] == 1 && listVertex[i]->getColor() == WHITE) {
					dfs_visit(listVertex[i], time);
				}
			}
		}
	}
	time++;
	v->tm[1] = time;
	v->setColor(BLACK);
	dfs_list.push_back(v->getID());
}

void Graph::print_dfs_list() {
	cout << endl << "	====== DFS list =====" << endl;
	for (unsigned int i = 0; i < dfs_list.size(); i++) {
		cout << dfs_list[i]  << " : " << listVertex[dfs_list[i]-1]->tm[0] << "," << listVertex[dfs_list[i] - 1]->tm[1] << endl;
	}
	cout << "	======================" << endl;
}

/* Functions returns weight of the MST*/

int Graph::kruskalMST()
{
	cout << "	======================\nKruskal MST :\nEdge \tWeight\n";
	int mst_wt = 0; // Initialize result 

					// Sort edges in increasing order on basis of cost 
					//sort(edges.begin(), edges.end());

	vector<Edge*> cp_listEdge = listEdge;
	cp_listEdge = tri_vecteur_edge_par_poids(cp_listEdge);

	for (unsigned int i = 0; i < cp_listEdge.size(); i++)
	{
		Vertex* u = cp_listEdge[i]->get_v0();
		Vertex* v = cp_listEdge[i]->get_v1();

		Vertex* set_u = find(u);
		Vertex* set_v = find(v);

		// Check if the selected edge is creating 
		// a cycle or not (Cycle is created if u 
		// and v belong to same set) 
		if (set_u != set_v)
		{
			// Current edge will be in the MST 
			// so print it 
			cout << u->getID() << " - " << v->getID() << "\t" << cp_listEdge[i]->getPoids() << endl;

			// Update MST weight 
			mst_wt += cp_listEdge[i]->getPoids();

			// Merge two sets 
			merge(cp_listEdge[i]);

		}
	}
	for (unsigned int i = 0; i < sizeV; i++) {
		listVertex[i]->setParent(listVertex[i]);
	}
	return mst_wt;
}

vector<Edge*> Graph::tri_vecteur_edge_par_poids(vector<Edge*> _listEdge) {
	vector<Edge*> listEdge_tri;
	listEdge_tri.push_back(_listEdge[0]);
	unsigned int cpt = 0;
	bool test;
	for (unsigned int i = 1; i < _listEdge.size(); i++) {
		test = 1;
		while (test) {
			if (cpt == listEdge_tri.size()) {
				cpt = 0;
				test = 0;
				listEdge_tri.push_back(_listEdge[i]);
			}
			else {
				if (listEdge_tri[cpt]->getPoids() > _listEdge[i]->getPoids()) {
					//listEdge_tri.push_back(listEdge_tri[cpt]);
					listEdge_tri.insert(listEdge_tri.begin() + (cpt + 1), listEdge_tri[cpt]);
					listEdge_tri[cpt] = _listEdge[i];
					cpt = 0;
					test = 0;
				}
				else {
					cpt++;
				}
			}
		}
	}
	return listEdge_tri;
}

void Graph::merge(Edge* e)
{

	Vertex* x = e->get_v0()->getParent();
	Vertex* y = e->get_v1()->getParent();
	// Make tree with smaller height a subtree of the other tree
	if (x->getRank() > y->getRank())
		y->getParent()->setParent(x);
	else // If rnk[x] <= rnk[y] 
		x->getParent()->setParent(y);

	if (x->getRank() == y->getRank())
		y->setRank(y->getRank() + 1);

}

Vertex* Graph::find(Vertex* _u)
{
	Vertex* u = _u;
	Vertex* res = u->getParent();
	// Make the parent of the nodes in the path	from u--> parent de u pointe vers parent de u
	if (u != u->getParent())
		res->setParent(find(res->getParent()));
	return res->getParent();
}

// A utility function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST
int Graph::minKey(vector<Vertex*> cp_listeVertex, vector<bool> mstSet)
{
	// Initialize min value 
	int min = INT_MAX;
	int min_index;

	for (unsigned int v = 0; v < sizeV; v++)
		if (mstSet[v] == false && cp_listeVertex[v]->getKey() < min) {
			min = cp_listeVertex[v]->getKey();
			min_index = v;
		}

	return min_index;
}

int Graph::primMST()
{

	int mst_wt = 0;

	vector<Edge*> cp_listEdge = listEdge;
	vector<Vertex*> cp_listVertex = listVertex;


	// Initialize all keys as INFINITE 
	for (unsigned int i = 0; i < sizeV; i++) {
		cp_listVertex[i]->setKey(INT_MAX);
	}
	// Always include first 1st vertex in MST. 
	// Make key 0 so that this vertex is picked as first vertex. 
	cp_listVertex[0]->setKey(0);  

	// The MST will have V vertices
	cout <<"	======================\nPrim MST :\nEdge \tWeight\n";

	for (unsigned int i = 1; i < sizeV; i++) { // For each vertices
		for (unsigned int j = 0; j < cp_listEdge.size(); j++) {
			if (cp_listEdge[j]->get_ID_v0() == i) {
				if (cp_listEdge[j]->get_v1()->getKey() > cp_listEdge[j]->getPoids()) {
					cp_listEdge[j]->get_v1()->setParent(cp_listEdge[j]->get_v0());
					cp_listEdge[j]->get_v1()->setKey(cp_listEdge[j]->getPoids());
				}
			}
		}
	}

	for (unsigned int i = 0; i < cp_listEdge.size(); i++) {
		if (cp_listEdge[i]->get_v0() == cp_listEdge[i]->get_v1()->getParent()) {
			cout << cp_listEdge[i]->get_ID_v0() << " - " << cp_listEdge[i]->get_ID_v1() << "\t" << cp_listEdge[i]->getPoids()
				<< "\n";
			mst_wt += cp_listEdge[i]->getPoids();
		}
	}
	
	return mst_wt;
}
