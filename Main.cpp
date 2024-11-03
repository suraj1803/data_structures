#include <iostream>
#include "Tree/Tree.h"

using namespace std;

int main() {
  Node* node1 = new Node(1, 2, 3);
  Node* node2 = new Node(5, 6, 7);
  Node* root = new Node(4, node1, node2);

  BinaryTree tree(root);
  cout << tree << endl;
  /*
   * TODO review all the functions
   */

  int item;
  // cout << "Enter a item: ";
  // cin >> item;
  // Node* key1 = tree.findNode(item);
  // if (key1 == nullptr) { cout << key1 << " is not present" << endl; }
  // else {
  //   cout << "SubTreeFirst of node " << item << " is " << tree.subTreeFirst(key1)->item << endl;
  //   cout << "SubTreeLast of node " << item << " is " << tree.subTreeLast(key1)->item << endl;
  // }
  //
  // cout << "Enter a item: ";
  // cin >> item;
  // Node* key2 = tree.findNode(item);
  // if (key2 == nullptr) {
  //   cout << key2 << " is not present" << endl;
  // }
  // else {
  //   Node* successor = tree.successor(key2);  // Store successor in `succ`
  //   Node* predecessor = tree.predecessor(key2); // Store predecessor in `pred`
  //
  //   cout << "Successor of node " << item << " is ";
  //   if (successor == nullptr) {
  //     cout << "NULL" << endl;
  //   } else {
  //     cout << successor -> item << endl;
  //   }
  //   cout << "Predecessor of node " << item << " is ";
  //   if (predecessor == nullptr) {
  //     cout << "NULL" << endl;
  //   }
  //   else {
  //     cout << predecessor->item << endl;
  //   }
  // }
  //
  // cout << "Enter a item to insert after root: ";
  // cin >> item;
  // Node* newNode = new Node(item);
  // tree.insertAfter(root, newNode);
  // cout << "Inserted " << item << " after " << root->item << endl;
  // cout << tree << endl;
  //
  // cout << "Enter a item to insert before root: ";
  // cin >> item;
  // newNode = new Node(item);
  // tree.insertBefore(root, newNode);
  // cout << "Inserted " << item << " before " << root->item << endl;
  // cout << tree << endl;

  Node* n;
  cout << "Enter a item to delete: ";
  cin >> item;
  n = tree.findNode(item);
  tree.deleteNode(n);
  cout << tree << endl;


  return 0;
}
