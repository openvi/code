#include<iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node *reverseList(Node* node) {
    if (node->next) {
        Node *returned = reverseList(node->next);
        returned->next = node;
        node->next = NULL;
    }
    return node;
}

void reverseListNonRecursive(Node *node) {
    Node *first = node;
    Node *second = node->next;
    Node *head = first;
    while (second->next) {
        head->next = second->next;
        second->next = first;
        first = second;
        second = head->next;
    }

    second->next = first;
    head->next = NULL;
}

int main(){
    int x;
    Node *head;
    Node *current;
    while (cin>>x) {
        if (!head) {
            head = new Node();
            head->value = x;
            current = head;
        } else {
            Node* node = new Node();
            node->value = x;
            current->next = node;
            current = current->next;
        }
    }
    reverseListNonRecursive(head);
    while (current) {
        cout<<current->value<<" ";
        current = current->next;
    }
    return 0;
}
