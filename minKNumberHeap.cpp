#include<iostream>
using namespace std;

int heapSize;

void minHeaplify(int *a, int i) {
    int left = i *2;
    int right = i*2 +1;
    int smallest;
    smallest = i;
    if ((left < heapSize)  && (a[left] < a[i])){
        smallest = left;
    }

    if ((right < heapSize) && (a[right] < a[smallest])) {
        smallest = right;
    }
    if (smallest != i) {
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        minHeaplify(a, smallest);
    }
}

void buildHeap(int *a) {
    for (int i=heapSize/2; i>=0; i--) {
        minHeaplify(a, i);
    }
}

int extractTop(int *a) {
   int ret = a[0];
   a[0] = a[heapSize-1];
   heapSize--;
   minHeaplify(a, 0);
   return ret;

}

int main() {
    int a[10];
    int x;
    while (cin>>x) {
        a[heapSize++] = x;
    }
    buildHeap(a);
    cout << extractTop(a);

}
