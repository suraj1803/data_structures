#include <iostream>
#include "Tree/Tree.h"
using namespace std;


int main() {
	Node* node1 = new Node(1, 2, 3);
	Node* node2 = new Node(5, 6, 7);
	// Node* node3 = new Node(5);
	Node* root = new Node(node1, 4, node2);
	BinaryTree tree(root);
	tree.print();
	// int item;
	// cin >> item;
	Node* node = tree.subTreeFirst(root);
	cout << node << endl;
	// cin >> item;
	node = tree.subTreeLast(root);
	cout << node << endl;

	tree.subTreeFirstTest(root);
	tree.subTreeLastTest(root);

	return 0;
}
