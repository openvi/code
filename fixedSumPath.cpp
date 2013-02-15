#include<iostream>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
};

Node *tree;
int fixedSum = 22;
static int sum=0;
static int top=-1;

void insert2node(Node* pNode, Node* newNode) {
    if (newNode->value <= pNode->value) {
        if (pNode->left) {
            insert2node(pNode->left, newNode);
        } else {
            pNode->left = newNode;
        }
    } else {
        if (pNode->right) {
            insert2node(pNode->right, newNode);
        } else {
            pNode->right = newNode;
        }
    }
}

void inorderTraverse(Node *node, Node **path) {
    sum+=node->value;
    top++;
    path[top] = node;
    if (node->left) {
        inorderTraverse(node->left, path);
    }
   // cout<<node->value<<"\n";
    if (sum == fixedSum) {
        cout<<"hey:\n";
        for (int i=0;i<=top;i++) {
           cout<<path[i]->value<<" ";
        }
    }
    if (node->right) {
        inorderTraverse(node->right, path);
    }
    sum-=node->value;
    top--;
}

int main() {
    int x;
    while (cin>>x) {
        Node *newNode = new Node();
        newNode->value = x;
        if (!tree) {
            tree = newNode;
        } else {
            insert2node(tree, newNode);
        }
    }
    Node* path[10];
    top = -1;

    inorderTraverse(tree, path);
}
