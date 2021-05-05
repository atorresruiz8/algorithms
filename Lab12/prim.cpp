#include <iostream>
#include <list> // used to store a list of all the edges
#include <vector> // used to store edges
#include <limits> // used to have 'INT8_MAX' represent positive infinity
#include <queue> // used to implement a min priority queue
using namespace std;

struct Graph {
	int V; // number of vertices
	list <pair<int, int>> *adj; // adjacency list to represent the edges

	Graph(int V) { // constructor for new Graph objects
		this->V = V;
		adj = new list<pair<int, int>>[V]; // create a new adjacency list of size V to store all the edges
	}

	void addEdge(int u, int v, int w) {
		adj[u].push_back(make_pair(v, w)); // pair the vertix v with its weight w
		adj[v].push_back(make_pair(u, w)); // pair the vertix u with its weight w
	}
};

void prim(Graph G, int w, int r) {
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > Q; // min priority queue

	int key[G.V]; // array to store all the keys
	int pi[G.V]; // array to store the 'parents' of each vertex
	bool visited[G.V]; // array to check if an edge has been visited before (true if it has, false if it hasn't)

	for (int i = 0; i < G.V; i++) {
		visited[i] = false; // initialize every bool in the 'visited' check to false
	}

	for (int i = 0; i < G.V; i++) {
		key[i] = INT8_MAX; // represents positive infinity
		pi[i] = 0; // parent of the edge is NULL
	}

	Q.push(pair<int, int>(0, r)); // insert the root into the queue
	key[r] = 0; // root does not have a key
	pi[r] = 0; // root does not have a parent

	while (!Q.empty()) {
		int u = Q.top().second; // extracts the min element of the second object in the pair
		Q.pop(); // remove this element from the queue

		visited[u] = true; // this edge has been visited before

		list< pair<int, int> >::iterator i; // use an iterator to traverse the adjacency list

		for (i = G.adj[u].begin(); i != G.adj[u].end(); i++) { // check each edge in the adjacency list
			int v = (*i).first; // v is the first element in the pair
			int w = (*i).second; // w is the second element in the pair

			if (!visited[v] && w < key[v]) { // if v has not been visited (and is therefore still in the queue) and the weight is less than v's key
				pi[v] = u; // u is v's unique parent
				key[v] = w; // decrease the key
				Q.push(pair<int, int>(key[v], v)); // push the new key into the queue
			}
		}
	}

	for (int i = 1; i < G.V; i++) { // print the parent of each vertex
		cout << pi[i] << endl; // skips the root vertex since it does not have a parent
	}
}

int main() {
	int numVert; // number of vertices in the Graph
	cin >> numVert;

	int numEdge; // number of edges in the Graph
	cin >> numEdge;

	Graph G(numVert); // initialize a Graph with the input number of vertices

	int u, v, w; // vertices u and v with weight w

	int r = 0; // vertex 0 is used as root r

	for (int i = 0; i < numEdge; i++) {
		cin >> u >> v >> w;
		G.addEdge(u, v, w);
	}

	prim(G, w, r); // call the MST function

	return 0;
}