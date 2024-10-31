#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
  Node* node1 = new Node(1, 2, 3);
  Node* node2 = new Node(5, 6, 7);
  Node* root = new Node(4, node1, node2);

  BinaryTree tree(root);
  cout << tree << endl;

  int item;
  cout << "Enter a item: ";
  cin >> item;
  Node* key1 = tree.findItem(item);
  if (key1 == nullptr) {
    cout << key1 << " is not present" << endl;
  }
  else {
    cout << "SubTreeFirst of node " << item << " is " << tree.subTreeFirst(key1)->item << endl;
  }

  cout << "Enter a item: ";
  cin >> item;
  Node* key2 = tree.findItem(item);
  if (key2 == nullptr) {
    cout << key2 << " is not present" << endl;
  }
  else {
    cout << "Succesor of node " << item << " is " << tree.successor(key2)->item << endl;
  }

  return 0;
}
