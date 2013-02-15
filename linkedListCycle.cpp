#include<iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

bool cycle(Node *head) {
    Node *slow = head;
    Node *quick = head->next;
    while(slow->next && quick->next && quick->next->next) {
        slow = slow->next;
        quick = quick->next->next;
        if (slow == quick) {
            cout<<slow->value;
            return true;
        }
    }

    return false;

}


int main(){
    int x;
    Node *head;
    Node *current;
    int i;
    Node *intersection;
    while (cin>>x) {
        i++;
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
        if (i==3) {
            intersection = current;
        }
    }
    current->next = intersection;
    current = head;
    for (int i=0;i<=12;i++) {
        cout<< current->value<<" ";
        current = current->next;
    }
    cycle(head);
    return 0;
}
