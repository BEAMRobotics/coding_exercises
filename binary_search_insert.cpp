/*
  * Problem Description: https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem
  * Author: Nick Charron
*/

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:

  	void preOrder(Node *root) {

      	if( root == NULL )
          	return;

      	cout << root->data << " ";

      	preOrder(root->left);
      	preOrder(root->right);
    }


/*
Node is defined as

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        Node *newNode;
        if(root == NULL){
          root = new Node(data);
        } else if(data < root->data){
            if (root->left == NULL){
                newNode = new Node(data);
                root->left = newNode;
            } else {
                newNode = insert(root->left, data);
            }
        } else {
            if (root->right == NULL){
                newNode = new Node(data);
                root->right = newNode;
                return root;
            } else {
                newNode = insert(root->right, data);
            }
        }
        return root;
    }

};

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);

    return 0;
}
