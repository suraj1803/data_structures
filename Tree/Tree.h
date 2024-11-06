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
  private:
    Node* root;

	public:
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
				subTreeLastTest(node->right); }
		}

		Node* successor(Node* node) {
			if (node == nullptr){
				return nullptr;
			}
			else if (node->hasRightChild()){
				return subTreeFirst(node->right);
			}
			else {
				while (node->parent && node != node->parent->left) {
					node = node->parent;
				}
				return node->parent;
			}
		}

    void successorTest(Node* node) {
      if (node == nullptr) {
        return;
      }
      else {
        cout << "Successor of " << node << " " << successor(node) << endl;
        successorTest(node->left);
        successorTest(node->right);
      }
    }

		Node* predecessor(Node* node) {
			if (node == nullptr) {
				return nullptr;
			}
			else if (node->hasLeftChild()) {
				return subTreeLast(node->left);
			}
			else {
				while (node->parent && node != node->parent->right) {
					node = node->parent;
				}
				return node->parent;
			}
		}

		void predecessorTest(Node* node) {
			if (node == nullptr) {
				return;
			}
			else {
				cout << "Predecessor of " << node << " " << predecessor(node) << endl;
				predecessorTest(node->left);
				predecessorTest(node->right);
			}
		}

		void insertAfter(Node* node, Node* newNode) {
			if (!(node->hasRightChild())) {
				node->right = newNode;
			}
			else {
				Node* temp = subTreeFirst(node->right);
				temp->left = newNode;
			}
		}

		void insertBefore(Node* node, Node* newNode) {
			if (!(node->hasLeftChild())) {
				node->left = newNode;
			}
			else {
				Node* temp = subTreeLast(node->left);
				temp->right = newNode;
			}
		}

		int deleteNode(Node* node) {
			if (node == nullptr) {
				return -1;
			}
			if (node->isLeaf()) {
				int item = node->item;
				if (node->isRoot()) {
					delete node;
					root = nullptr;
					return item;
				}
				if (node->parent->left == node) {
					node->parent->left = nullptr;
				} else {
					node->parent->right = nullptr;
				}
				delete node;
				return item;
			}
			else {
				Node* temp;
				if (node->hasLeftChild()) {
					temp = predecessor(node);
				}
				else {
					temp = successor(node);
				}
				int t = node->item;
				node->item = temp->item;
				temp->item = t;
				return deleteNode(temp);
			}
		}

    Node* find(int key) {
      return find(root, key);
    }
  
		void print() {
			print(root);
			cout << endl;
		}

		~BinaryTree() {
			deleteTree(root);
		}


	private:
    Node* find(Node* root, int key) {
      if (root == nullptr || root->item == key) {
        return root;
      } else {
        Node* left = find(root->left, key);
        Node* right = find(root->right, key);
        if (left != nullptr) {
          return left;
        }
        else {
          return right;
        }
      }
    }

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

