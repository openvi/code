#include<iostream>
using namespace std;

int main(){
    int a[10];
    int x;
    int i;
    while (cin>>x) {
        a[i++] = x;
    }
    int ret=a[0];
    for (int j=1; j<i; j++) {
        ret = ret ^ a[j];
    }
    cout<<ret;
}
