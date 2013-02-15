#include<iostream>
using namespace std;

bool isPostOrder(int *a, int start, int end) {
    int mid = end-1;
    int endPtr = end-1;
    int startPtr = start;
    if (start == end) return true;
    if (end == start+1) return true;
    while ((endPtr>=start) && (a[endPtr]>=a[end])){
        endPtr--;
    }
    //don't need to care about endPtr==start
    if (endPtr > start) {
        mid = endPtr;
        while ((endPtr>=start) && (a[endPtr]<=a[end])) {
            endPtr--;
        }
    }

    if (!isPostOrder(a,endPtr,end-1)) {
        return false;
    }

    if (endPtr!=start-1) {
        return false;
    }

    if (mid>start) {
         return (isPostOrder(a, start, mid) &&  isPostOrder(a, mid,end-1));
    }else {
        return isPostOrder(a, start, end-1);
    }

}

int main(){
    int a[10];
    int i;
    int x;
    while (cin>>x) {
        a[i++] = x;
    }
    if (isPostOrder(a, 0, i-1)) {
        cout << "yeah";
    }
}
