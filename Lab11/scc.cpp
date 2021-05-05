#include <iostream>

using namespace std;

int time = 0; // timestamp for discovering edges in DFS

struct Graph {
	int V; // number of vertices
	int E; // number of edges

	Graph(int V, int E) { // constructor for a graph with user input vertices and edges
		this->V = V;
		this->E = E;
	}
};

void printSSC(Graph G) {

}

void DFSVisit(Graph G) {

}

void DFS(Graph G) {

}

void SSC(Graph G) {

}

int main() {
	int numVert;
	cin >> numVert;

	int numEdge;
	cin >> numEdge;

	Graph G(numVert, numEdge);

	SSC(G);

	return 0;
}