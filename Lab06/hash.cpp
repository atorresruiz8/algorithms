#include <iostream>
#include <list> // used to have a linked list represent the hash table

using namespace std;

void hashPrint(list<int>* table, int m) { // function to print out the entire hash table
	list<int>::iterator i; // iterate through each node in the list

	for (int j = 0; j < m; j++) {
		cout << j << ":"; // hash value

		for (i = table[j].begin(); i != table[j].end(); i++) {
			cout << *i << "->"; // print the keys in each list
		} 
		
		if (distance(table[j].begin(), i) == table[j].size()) { // if the iterator is at the last key in the list (i.e. the index equal to the size of the list), print a ;
			cout << ";";
		} cout << endl;
	}
}

bool hashSearch(list<int>* table, int key, int m) { // searching function
	int h = key % m; // hash function
	
	bool found; // returns true if key is found, false if not

	list<int>::iterator i; // use an iterator to check each key in the list
	
	int index = 0; // index for each key

	for (i = table[h].begin(); i != table[h].end(); i++) {
		if (*i == key) { // if the dereferenced iterator is pointing to the key, tell us the hash value and index it is stored in
			cout << key << ":" << "FOUND_AT" << h << "," << index << ";" << endl;
			
			found = true;
			
			return true;
		} index++; // increase index to check the next index in the list
	} if (!found) { // if found is not true, the key is not in the table and cannot be found
		cout << key << ":" << "NOT_FOUND;" << endl;
	}
	return false;
}

void hashInsert(list<int>* table, int key, int m) { // insert a value to the table based on its hash value
	int h = key % m; // hash function
	
	table[h].push_front(key);
}

bool hashDelete(list<int>* table, int key, int m) { // delete a value from the hash table
	int h = key % m; // hash function
	
	list<int>::iterator i; // use an iterator to check every key in the list
	
	bool found; // returns true if key is found, false if not

	int count = 0; // used for counting if there are multiple of the same keys (so only the earliest one is deleted)

	for (i = table[h].begin(); i != table[h].end(); i++) { 
		if (*i == key) { // if the dereferenced iterator points to the key, delete this key from the table
			table[h].erase(i);
			
			found = true;

			cout << key << ":" << "DELETED;" << endl;
			
			return true;
		} count++; // increase count to check for multiples of the same key
	} if (!found) { // if found is not true, then the key is not in the hash table and cannot be deleted
		cout << key << ":" << "DELETE_FAILED;" << endl;
	}
	return false;
}

int main() {
	int m; // size of hash table 
	cin >> m;
	
	list<int>* table = new list<int>[m]; // linked list hash table

	int key; // keys to be inserted into hash table

	char command; // used to call each function
	cin >> command;

	while (command != 'e') { // continue using functions until exit is called
		if (command == 'e') { // if 'e' is entered, exit program
			return 0;
		}

		else if (command == 'o') { // if 'o' is entered, print out the hash table
			hashPrint(table, m);
		}

		else if (command == 'i') { // if 'i' is entered, insert key to table
			cin >> key;
			hashInsert(table, key, m);
		}

		else if (command == 'd') { // if 'd' is entered, delete key from table (if it's there)
			cin >> key;
			hashDelete(table, key, m);
		}

		else if (command == 's') { // if 's' is entered, search for key in table
			cin >> key;
			hashSearch(table, key, m);
		}

		cin >> command; // ask for input again
	}

	delete[] table; // free up memory used by table

	return 0;
}