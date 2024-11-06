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

	tree.subTreeFirstTest(root);
	tree.subTreeLastTest(root);
  tree.successorTest(root);

	return 0;
}
