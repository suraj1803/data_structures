#pragma once
#include <iostream>
using namespace std;

class Node{
	public:
		int item;
		Node* parent;
		Node* left;
		Node* right;
		Node(int item) {
			this->item = item;
			this->parent = nullptr;
			this->left = nullptr;
			this->right = nullptr;
		}

		Node(Node* left, int item, Node* right) {
			this->item = item;
			this->left = left;
			this->right = right;
			left->parent = this;
			right->parent = this;
		}
		Node(int left, int item, int right) {
			Node* leftNode = new Node(left);
			Node* rightNode = new Node(right);
			this->item = item;
			this->left = leftNode;
			this->right = rightNode;
			leftNode->parent = this;
			rightNode->parent = this;
		}

		bool hasLeftChild() {
			return left != nullptr;
		}
		bool hasRightChild() {
			return right != nullptr;
		}

		bool isLeaf() {
			return right == nullptr && left == nullptr;
		}

		bool isRoot() {
			return parent == nullptr;
		}

		friend ostream& operator<<(ostream& out, Node* node);
};

inline ostream& operator<<(ostream& out, Node* node) {
	if (node != nullptr)
		out << node->item << " ";
	else 
		out << "null ";
	return out;
}

class BinaryTree {
		
	public:
		Node* root;
		BinaryTree(Node* root) {
			this->root = root;
		}

		Node* subTreeFirst(Node* node) {
			if (node == nullptr || !(node->hasLeftChild()) || node->isLeaf()) { return node; }
			else {
				return subTreeFirst(node->left);
			}
		}

		void subTreeFirstTest(Node* node) {
			if (node == nullptr) {
				return;
			} else {
				Node* res = subTreeFirst(node);
				cout << "SubTreeFirst of " << node  << " is " << res << endl;
				subTreeFirstTest(node->left);
				subTreeFirstTest(node->right);
			}
		}

		Node* subTreeLast(Node* node)  {
			if (node == nullptr || !(node->hasRightChild()) || node->isLeaf()) {
				return node;
			}
			else {
				return subTreeLast(node->right);
			}
		}
		void subTreeLastTest(Node* node) {
			if (node == nullptr) {
				return;
			} else {
				Node* res = subTreeLast(node);
				cout << "SubTreeLast of " << node  << " is " << res << endl;
				subTreeLastTest(node->left);
				subTreeLastTest(node->right);
			}
		}

		Node* succcessor(Node* node) {
			if (node == nullptr){
				return nullptr;
			}
			else if (node->hasRightChild()){
				return subTreeFirst(node->right);
			}
			else if (node->isRoot()){
				return nullptr;
			}
			else {
				while (node->parent->left != node) {
					node = node->parent;
				}
				return node;
			}
		}

		// Node* find(int item) {
		// 	if (root == nullptr) {
		//
		// 	}
		// }


		void print() {
			print(root);
			cout << endl;
		}

		~BinaryTree() {
			deleteTree(root);
		}

	private:
		void print(Node* root) {
			if (root == nullptr) {
				return;
			}
			else {
				print(root->left);
				cout << root << " ";
				print(root->right);
			}
		}

		void deleteTree(Node* root) {
			if (root == nullptr) {
				return;
			}
			else {
				deleteTree(root->left);
				deleteTree(root->right);
				delete root;
			}
		}
};

