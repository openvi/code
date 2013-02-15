#include<stack>
#include<iostream>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
};
void mirrorTree(Node *node) {
    Node* temp;
    if (!node) {
        return;
    }
    temp = node->left;
    node->left = node->right;
    temp->right = temp;
    mirrorTree(node->left);
    mirrorTree(node->right);
}

//other one
void printTreeByLevel(Node *node) {
    stack <Node *> s ;
    Node * root;
    s.push(root);
    while (s.size()>0) {
        Node *node = s.pop();
        if (node->left) {
            s.push(node->left);
        }
        if (node->right) {
            s.push(node->right);
        }
        cout<<node->value;
    }



}
