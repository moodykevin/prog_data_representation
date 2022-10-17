#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  root = insert(root, x);
}
//HELPER
AVLNode* AVLTree::insert(AVLNode* n, const string& x) {
  if(!n){return new AVLNode(x);}

  if(x>n->value){
    n->right = insert(n->right, x);
  } else if (x<n->value) {
    n->left = insert(n->left, x);
  }

  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  
  return n;
}


// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  AVLNode *m = n->right;
  AVLNode *temp = m->left;
  m->left = n;
  n->right = temp;
  n->height = max(height(n->left), height(n->right)) + 1;
  m->height = max(height(m->left), height(m->right)) + 1;
  return m;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  AVLNode *m = n->left;
  AVLNode *temp = m->right;
  m->right = n;
  n->left = temp;
  n->height = max(height(n->left), height(n->right)) + 1;
  m->height = max(height(m->left), height(m->right)) + 1;
  return m;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  int bFactor = height(n->right) - height(n->left);

  if(bFactor == 2){
    if(height(n->right->right)-height(n->right->left) < 0){
      n->right = rotateRight(n->right);
    }
    n = rotateLeft(n);
  } else if(bFactor == -2){
    if(height(n->left->right) - height(n->left->left) > 0){
      n->left = rotateLeft(n->left);
    }
    n = rotateRight(n);
  }
}






// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
  if(find(x)){
    return pathTo(root, x);
  } else { return ""; }}
//HELPER
string AVLTree::pathTo(AVLNode* n, const string& x) const {
  string s = n->value;
  if(!n){return "";}
  if(x == n->value){return s;}
  if(x > n->value){
    return s + " " + pathTo(n->right, x);
  } else if (x < n->value){
    return s + " " + pathTo(n->left, x);
  }
  return "";
}


// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {return find(root, x);}
//HELPER
bool AVLTree::find(AVLNode* n, const string& x) const {
  if (!n){return false;}
  if(x == n->value){return true;}
  if(x > n-> value){
    return find(n->right, x);
  } else if (x < n->value){
    return find(n->left, x);
  }
  return false;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {return numNodes(root);}
// HELPER
int AVLTree::numNodes(AVLNode* n) const {
  if(!n){
    return 0;
  }
  else{
    return 1 + numNodes(n->left) + numNodes(n->right);
  }
  return 0;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
