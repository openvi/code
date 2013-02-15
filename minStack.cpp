#include<iostream>
using namespace std;
struct stackElement {
    int data;
    int min;
};

struct minStack {
    stackElement *data;
    int top;
    int size;
} stack;

void push(int x) {
    stack.top++;
    stack.data[stack.top].data = x;
    if (((stack.top-1) >= 0) && (x > stack.data[stack.top - 1].min)) {
        stack.data[stack.top].min = stack.data[stack.top-1].min;
    } else {
        stack.data[stack.top].min = x;
    }

}

stackElement pop() {
    if (stack.top>=0) {
        stack.top-=1;
        return stack.data[stack.top+1];
    }
}

int min() {
    if (stack.top>=0) {
        return stack.data[stack.top].min;
    }
}

int main() {
int n = 10;
stack.data = new stackElement[n];
stack.size = 10;
stack.top = -1;
int x;
while (cin>>x) {
    push(x);

}
 cout << min();
 return 0;
}
