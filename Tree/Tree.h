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

    Node(int item, Node* left, Node* right) {
      this->item = item;
      this->left = left;
      this->right = right;
      left->parent = this;
      right->parent = this;
    }

    Node(int leftItem, int item, int rightItem) {
      Node* left = new Node(leftItem);
      Node* right = new Node(rightItem);
      this->item = item;
      this->left = left;
      this->right = right;
      left->parent = this;
      right->parent = this;
    }

    bool hasLeftChild() {
      return left != nullptr;
    }

    bool hasRightChild() {
      return right != nullptr;
    }

    bool isLeaf() {
      return left == nullptr && right == nullptr;
    }

};


class BinaryTree{
  private:
    Node* root;

  public:
    BinaryTree(Node* root) {
      this->root = root;
    }

    Node* subTreeFirst(Node* node) {
      if (node == nullptr) {
        return nullptr;
      }
      if (node->hasLeftChild()) {
        while (!(node->isLeaf())) {
          node = node->left;
        }
      }
      return node;
    }

    Node* subTreeLast(Node* node) {
      if (node == nullptr) {
        return nullptr;
      }
      if (node->hasRightChild()) {
        while (!(node->isLeaf())) {
          node = node->right;
        }
      }
      return node;
    }


    Node* successor(Node* node) {
      if (node == nullptr) {
        return nullptr;
      }
      if (node->hasRightChild()) { 
        return subTreeFirst(node->right);
      } else {
        while(node != node->parent->left) {
          node = node->parent;
          if (node->parent == nullptr) {
            return nullptr;
          }
        }
        return node->parent;
      }
    }

    Node* predecessor(Node* node) {
      if (node == nullptr) {
        return nullptr;
      }
      if (node->hasLeftChild()) {
        return subTreeLast(node->left);
      } else {
        while (node != node->parent->right) {
          node = node -> parent;
          if (node -> parent == nullptr) {
            return nullptr;
          }
        }
        return node->parent;
      }
    }

    Node* findItem(int item) {
      return findItem(root, item);
    }

    bool hasPredecessor(Node* node) {
      return predecessor(node) != nullptr;
    }

    bool hasSuccessor(Node* node) {
      return successor(root) != nullptr;
    }

    friend ostream& operator<<(ostream& out,const BinaryTree& tree);

    ~BinaryTree() {
      deleteNode(root);
    }

  private:
    void print(Node* node, ostream& out) const{
      if (node == nullptr) {
        return;
      } else {
        print(node->left, out);
        out << node->item << " ";
        print(node->right, out);
      }
    }

    void deleteNode(Node* node) {
      if (node == nullptr) {
        return;
      } else {
        deleteNode(node->left);
        deleteNode(node->right);
        delete node;
      }
    }

    Node* findItem(Node* root, int item) {
      if (root == nullptr || root->item == item) {
        return root;
      }
      else {
        Node* left = findItem(root->left, item);
        Node* right = findItem(root->right, item);
        if (left != nullptr) {
          return left;
        }
        else {
          return right;
        }
      }
    }
};

inline ostream& operator<<(ostream& out, const BinaryTree& tree) {
  tree.print(tree.root, out);
  return out;
}
