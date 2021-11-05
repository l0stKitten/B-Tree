#include <iostream>

// A BTree node
class BTreeNode
{
  public:
    int *keys;  // An array of keys
    int t;      // Minimum degree (defines the range for number of keys)
    BTreeNode **C; // An array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false

    BTreeNode(int _t, bool _leaf);   // Constructor
 
    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();
 
    // A function to search a key in the subtree rooted with this node.   
    BTreeNode *search(int k);   // returns NULL if k is not present.

    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    
    int findKey(int k);
    void remove(int k);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPred(int idx);
    int getSucc(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);
 
// Make the BTree friend of this so that we can access private members of this
// class in BTree functions
friend class BTree;
};
 
// A BTree
class BTree
{
  public:
    BTreeNode *root; // Pointer to root node
    int t;  // Minimum degree

    // Constructor (Initializes tree as empty)
    BTree(int _t)
    {  root = NULL;  t = _t; }
 
    // function to traverse the tree
    void traverse()
    {  if (root != NULL) root->traverse(); }
 
    // function to search a key in this tree
    BTreeNode* search(int k)
    {  return (root == NULL)? NULL : root->search(k); }
    void insert(int k);
    void remove(int k);
};