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

    bool isRoot() {
      return parent == nullptr;
    }

    bool isLeftChild() {
      if (isRoot()) {
        return false;
      }
      else {
        return parent->left->item == item;
      }
    }

    bool isRightChild() {
      if (isRoot()) {
        return false;
      }
      else {
        return parent->right->item == item;
      }
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

    void insertAfter(Node* node, Node* newNode) {
      if (!node->hasRightChild()) {
        node->right = newNode;
        newNode->parent = node;
      } else {
        Node* nextNode = subTreeFirst(node->right);
        nextNode->left = newNode;
        newNode->parent = nextNode;
      }
    }

    void insertBefore(Node* node, Node* newNode) {
      if (!node->hasLeftChild()) {
        node->left = newNode;
        newNode->parent = node;
      } else {
        Node* prevNode = subTreeLast(node->left);
        prevNode->right = newNode;
        newNode->parent = prevNode;
      }
    }
    int deleteNode(Node* node) {
      if (node == nullptr) {
        return -1;
      }
      int item = node->item;

      if (node->isLeaf()) {
        if (node->isRoot()) { 
          delete node;
          root = nullptr;
        }
        else {
          Node* tempParent = node->parent;
          bool isLeft = node->isLeftChild();
          delete node;
          if (isLeft) {
            tempParent->left = nullptr;
          }
          else {
            tempParent->right = nullptr;
          }
        }
        return item;
      }
      else {
        if (node->hasLeftChild()) {
          Node* prev = predecessor(node);
          // cout << "predecessor "  << "of " << node->item << " -> " << prev->item << endl;
          swap(node->item, prev->item);
          deleteNode(prev);
        }
        else {
          Node* next = successor(node);
          swap(node->item, next->item);
          deleteNode(next);
        }
        return item;
      } 
    }

    Node* findNode(int item) {
      return findNode(root, item);
    }

    bool hasPredecessor(Node* node) {
      return predecessor(node) != nullptr;
    }

    bool hasSuccessor(Node* node) {
      return successor(node) != nullptr;
    }

    friend ostream& operator<<(ostream& out,const BinaryTree& tree);

    ~BinaryTree() {
      deleteTree(root);
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

    void deleteTree(Node* node) {
      if (node == nullptr) {
        return;
      } else {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
      }
    }

    Node* findNode(Node* root, int item) {
      if (root == nullptr || root->item == item) {
        return root;
      }
      else {
        Node* left = findNode(root->left, item);
        Node* right = findNode(root->right, item);
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
