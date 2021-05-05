#include <iostream>
#include <string> // uses strings to store the choice on which function to use
#include <sstream> // used to separate the int to be inserted from the 'i' and 'd' functions
using namespace std;

struct Node { // structure for the nodes in the BST
	int key;
	Node* left;
	Node* right;
	Node* parent; // used for deletion
};

void printInOrder(Node* x) { // print the BST in order
	if (x != NULL) { // if the root node isn't empty, print
		printInOrder(x->left); // print left subtree
		cout << x->key << endl; // print root
		printInOrder(x->right); // print right subtree
	}
}

void printPreOrder(Node* x) { // prints the root before the values in either subtree
	if (x != NULL) { // if the root node isn't empty, print
		cout << x->key << endl; // print root
		printPreOrder(x->left); // print left subtree
		printPreOrder(x->right); // print right subtree
	}
}

void printPostOrder(Node* x) { // prints the root after the values in either subtree
	if (x != NULL) { // if the root node isn't empty, print
		printPostOrder(x->left); // print left subtree
		printPostOrder(x->right); // print right subtree
		cout << x->key << endl; // print root
	}
}

void treeInsert(Node* &root, int k) { // insert a value into the BST
	Node* y = NULL;
	Node* x = root;

	Node* z = new Node(); // this is the node we're inserting, it has a key of value 'k' and no right or left subtree
	z->key = k;
	z->left = NULL;
	z->right = NULL;

	while (x != NULL) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	} z->parent = y;

	if (y == NULL) { // if y was null, this means the BST was still empty. set the new node as the root
		root = z;
	}
	else if (z->key < y->key) {
		y->left = z;
	}
	else {
		y->right = z;
	}
}

Node* treeSearch(Node* &root, int key) { // returns a pointer to the node with the value 'key' 
	Node* x = root;

	while (x != NULL && key != x->key) {
		if (key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	} return x;
}

Node* treeMin(Node* x) { // returns a pointer to the minimum element in the subtree at this given node (used for deletion)
	while (x->left != NULL) {
		x = x->left;
	}

	return x;
}

void transplant(Node* &root, Node* u, Node* v) { // replaces one subtree as a child of its parent with another subtree
	if (u->parent == NULL) {
		root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}

	if (v != NULL) {
		v->parent = u->parent;
	}
}

void treeDelete(Node* &root, int key) { // deletes a node from the tree by using a combination of transplant and tree-min functions
	Node* y = new Node();
	Node* z = treeSearch(root, key); // search to see if the key is in the BST

	if (z == NULL) { // if the key isn't in the BST (thus, z is empty), do nothing
		return;
	}

	if (z->left == NULL) { // if z doesn't have a left subtree, fix this by transplanting one onto it
		transplant(root, z, z->right);
	}
	else if (z->right == NULL) { // else if z doesn't have a right subtree, transplant one onto it
		transplant(root, z, z->left);
	}

	else {
		y = treeMin(z->right);

		if (y->parent != z) {
			transplant(root, y, y->right);

			y->right = z->right;

			y->right->parent = y;
		}

		transplant(root, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}

int main() {
	int k; // keys to insert/delete
	Node* root = NULL; // pointer to root Node

	string func; // checks which function is going to be used
	cin >> func;

	while (func != "e") {
		if (func == "e") { // if 'e' is input, end the program
			return 0;
		}

		else if (func[0] == 'i') { // if 'i' is input, insert the given key to the BST
			string key = func.substr(1, func.length() - 1); // since the first character of the string 'func' is 'i,' the rest of the string is the key we are inserting
			stringstream ss(key); // use a stringstream to extract the string 'key' and convert it into an int
			ss >> k; // read the stringstream into the int k
			treeInsert(root, k); // insert k into the tree using pointer root as a reference
		}

		else if (func[0] == 'd') { // if 'd' is input, delete the given key from the BST (if it exists)
			string key = func.substr(1, func.length() - 1); // since the first character of the string 'func' is 'd,' the rest of the string is the key we are deleting
			stringstream ss(key); // use a stringstream to extract the string 'key' and convert it into an int
			ss >> k; // read the stringstream into the int k
			treeDelete(root, k); // delete k (if it exists) from the tree using pointer root as a reference
		}

		else if (func == "opre") { // if 'opre' is input, print the BST in pre-order
			printPreOrder(root);
		}

		else if (func == "opost") { // if 'opost' is input, print the BST in post-order
			printPostOrder(root);
		}

		else if (func == "oin") { // if 'oin' is input, print the BST in order
			printInOrder(root);
		} cin >> func; // ask for a choice in function again
	}

	delete[] root; // free the memory taken up by the root
	return 0;
}