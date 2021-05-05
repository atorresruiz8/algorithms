#include <iostream>
#include <queue> // used to implement a priority queue
using namespace std;

struct Node { // structure for the nodes in the Huffman tree
	char name;
	Node* left;
	Node* right;
	int freq;

	Node(char name, int freq) { // constructor for new Nodes
		this->name = name;
		this->freq = freq;
		left = NULL;
		right = NULL;
	}
};

struct compare { // used to compare the frequencies of two nodes
	bool operator()(Node* a, Node* b) {
		return (a->freq > b->freq);
	}
};

void print(string huffCodes[], char set[]) { // print out the Huffman codes
	for (int i = 0; i < 6; i++) { // check each of the 6 characters in the 'set' array
		cout << set[i] << ":" << huffCodes[i] << endl; // print the character and code associated with it
	}
}

void generateCode(Node* root, string code, char set[], string huffCodes[]) { // prints out the Huffman codes
	if (root == NULL) { // if the root node is empty, don't do anything
		return;
	}
	if (root->name != 'z') { // print out the character + code if the node's name is the same as the character in set
		for (int i = 0; i < 6; i++) {
			if (root->name == set[i]) { // check to see if the name attached to this node is the same as a character in the array
				huffCodes[i] = code; // store the string that contains the code into an array to print from
			}
		}
	} generateCode(root->left, code + "0", set, huffCodes); // go to the left child
	generateCode(root->right, code + "1", set, huffCodes); // go to the right child 
}

Node* huffman(char set[], int freq[], string huffCodes[]) { // creates the Huffman tree
	Node* x;
	Node* y;

	priority_queue<Node*, vector<Node*>, compare> Q; // priority queue keyed to the frequency of the Nodes

	for (int i = 0; i < 6; i++) { // fill the queue with the characters and frequencies input
		Q.push(new Node(set[i], freq[i]));
	}

	for (int i = 0; i < 6; i++) {
		Node* z = new Node('z', 0); // allocate a new node as the merger of the two nodes with lowest frequencies

		x = Q.top(); // extract min value in the priority Q, which is the top element
		z->left = x;
		Q.pop(); // remove this element from the queue

		y = Q.top(); // extract min value in the priority queue, which is the top element
		z->right = y;
		Q.pop(); // remove this element from the queue

		z->freq = x->freq + y->freq; // update the frequency of the merged node with the sum of the two merged nodes' frequencies

		Q.push(z); // insert z into the queue
	} Node* root = Q.top(); // root of the tree, since it is the final value in the queue

	generateCode(root, "", set, huffCodes);

	print(huffCodes, set);

	return root; // returns the root of the tree
}

int main() {
	int Afreq; // frequency of 'A'
	cin >> Afreq;

	int Bfreq; // frequency of 'B'
	cin >> Bfreq;

	int Cfreq; // frequency of 'C'
	cin >> Cfreq;

	int Dfreq; // frequency of 'D'
	cin >> Dfreq;

	int Efreq; // frequency of 'E'
	cin >> Efreq;

	int Ffreq; // frequency of 'F'
	cin >> Ffreq;

	char set[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	int freq[] = { Afreq, Bfreq, Cfreq, Dfreq, Efreq, Ffreq };

	string huffCodes[10]; // string array used to contain the huffman codes

	huffman(set, freq, huffCodes);

	return 0;
}