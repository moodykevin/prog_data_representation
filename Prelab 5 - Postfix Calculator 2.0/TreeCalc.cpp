// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  expressionStack = stack<TreeNode*>();
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  expressionStack.pop();
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if(tree == NULL){
    return;
  } else {
    cleanTree(tree->right);
    cleanTree(tree->left);
    delete tree;
  }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
  TreeNode *node = new TreeNode(val);
    if(val == "+" || val == "-" || val == "*" || val == "/"){
    node->right = expressionStack.top();
    expressionStack.pop();
    node->left = expressionStack.top();
    expressionStack.pop();
  } 
  expressionStack.push(node);
    // insert a value into the tree
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
   if(tree == NULL){
    return;
  } else {
    cout << tree->value << " ";
    printPrefix(tree->left);
    printPrefix(tree->right);
  }
    // print the tree in prefix format
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
  if(tree == NULL){
    return;
  } else {
    if(!isdigit(tree->value[tree->value.length()-1])){
      cout << "(";
    }
    printInfix(tree->left);
    
    if(!isdigit(tree->value[tree->value.length()-1])){
	cout << " " << tree->value << " ";
    } else {
    cout << tree->value;
    }
    printInfix(tree->right);
    if(!isdigit(tree->value[tree->value.length()-1])){
      cout << ")";
    }

  }
    // print tree in infix format with appropriate parentheses
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
  if(tree == NULL){
    return;
  } else {
    printPostfix(tree->left);
    printPostfix(tree->right);
    cout << tree->value << " ";
  }
    // print the tree in postfix form
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
  if(tree == NULL){
    return 0;
  }

  int right;
  int left;
  
  if(!tree-> left && !tree->right){
    return stoi(tree->value);
  }

  right = calculate(tree->right);
  left = calculate(tree->left);

  if(tree->value == "+"){
    return left+right;
  }

  if(tree->value == "-" && tree->value.length() == 1){
    return left-right;
  }

  if(tree->value == "*"){
    return left*right;
  }

  if(tree->value == "/"){
    return left/right;
  }


  return 0;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  int result = calculate(expressionStack.top());
  cleanTree(expressionStack.top());
  return result;
}
