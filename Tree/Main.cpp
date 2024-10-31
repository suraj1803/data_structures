#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
  Node* node1 = new Node(1, 2, 3);
  // Node* node2 = new Node(5, 6, 7);
  // Node* root = new Node(4, node1, nullptr);

  BinaryTree tree(node1);
  cout << tree << endl;

  int item;
  cout << "Enter a item: ";
  cin >> item;
  Node* key1 = tree.findItem(item);
  if (key1 == nullptr) { cout << key1 << " is not present" << endl; }
  else {
    cout << "SubTreeFirst of node " << item << " is " << tree.subTreeFirst(key1)->item << endl;
    cout << "SubTreeLast of node " << item << " is " << tree.subTreeLast(key1)->item << endl;
  }

  cout << "Enter a item: ";
  cin >> item;
  Node* key2 = tree.findItem(item);
  if (key2 == nullptr) {
    cout << key2 << " is not present" << endl;
  }
  else {
    Node* successor = tree.successor(key2);  // Store successor in `succ`
    Node* predecessor = tree.predecessor(key2); // Store predecessor in `pred`

    cout << "Successor of node " << item << " is ";
    if (successor == nullptr) {
      cout << "NULL" << endl;
    } else {
      cout << successor -> item << endl;
    }
    cout << "Predecessor of node " << item << " is ";
    if (predecessor == nullptr) {
      cout << "NULL" << endl;
    }
    else {
      cout << predecessor->item << endl;
    }
  }

  return 0;
}
