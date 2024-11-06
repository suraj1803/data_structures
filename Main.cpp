#include <iostream>
#include "Tree/Tree.h"
using namespace std;


int main() {
	// Node* node1 = new Node(1, 2, 3);
	// Node* node2 = new Node(5, 6, 7);
	// // Node* node3 = new Node(5);
	// Node* root = new Node(node1, 4, node2);
	// BinaryTree tree(root);
	// tree.print();

	// tree.subTreeFirstTest(root);
	// tree.subTreeLastTest(root);
	//  tree.successorTest(root);
	// tree.predecessorTest(root);
	//
	// while(true) {
	// 	int item;
	// 	cout << "Enter the node before you want to insert: ";
	// 	cin >> item;
	// 	Node* node = tree.find(item);
	// 	cout << "Enter the node you want to insert: ";
	// 	cin >> item;
	// 	Node* newNode = new Node(item);
	// 	tree.insertBefore(node, newNode);
	// 	tree.print();
	// }

	// while(true) {
	// 	int item;
	// 	cout << "Enter the node you want to delete: ";
	// 	cin >> item;
	// 	Node* node = tree.find(item);
	// 	cout << node << endl;
	// 	tree.deleteNode(node);
	// 	tree.print();
	// }

	int arr[] = {1, 2, 3, 4, 5};
	int n = size(arr);
	BinaryTree tree(arr, n);
	tree.print();

	return 0;
}
