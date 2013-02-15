#include<iostream>
#include<cstdio>
using namespace std;
struct BSTNode {
     int value;
     BSTNode* leftChild;
     BSTNode* rightChild;
};

typedef BSTNode BSTTree;
BSTTree* current;
BSTTree* listHead;

void insert2node(BSTTree* pNode, BSTTree* newNode) {
    if (newNode->value <= pNode->value) {
        if (pNode->leftChild) {
            insert2node(pNode->leftChild, newNode);
        } else {
            pNode->leftChild = newNode;
        }
    } else {
        if (pNode->rightChild) {
            insert2node(pNode->rightChild, newNode);
        } else {
            pNode->rightChild = newNode;
        }
    }
}

void insert2list(BSTTree *node) {
    listHead->rightChild = node;
    node->leftChild = listHead;
    listHead = node;
}

void inorderTraverse(BSTTree *node) {
    if (node->leftChild) {
        inorderTraverse(node->leftChild);
    }
    cout<<node->value<<"\n";
    insert2list(node);
    if (node->rightChild) {
        inorderTraverse(node->rightChild);
    }
}



void traverseList(BSTTree *head) {
    if (head) {
        cout<<head->value<<"\n";
        traverseList(head->rightChild);
    }
}

int main() {
    int x;
    current = new BSTTree();
    BSTTree* root;
    cout<<"please input an number\n";
    while (cin>>x) {
        if (!root) {
            root = current;
            root->value = x;
        } else {
            BSTTree* newNode = new BSTTree();
            newNode->value = x;
            insert2node(current, newNode);
        }
    }
    listHead = new BSTTree();
    BSTTree *newListHead = listHead;
    inorderTraverse(root);
    traverseList(newListHead);

    return 0;
}
