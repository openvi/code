#include<iostream>
using namespace std;

int maxSum(int a[], int size) {
    int start = 0;
    int end = 0;
    int max  = 1<<31 ;
    int sum = 0;
    while (end< size) {
        if (sum + a[end] >= 0 ) {
            sum = sum +a[end];
            if (sum > max) {
                max = sum;
            }
            end++;
        } else {
            end++;
            start = end;
            sum = 0;
        }
        cout << sum <<"\n";
    }
    cout<< max;
}

int main() {
 int x;
 int a[10];
 int i=0;
 while (cin>>x) {
    a[i++] = x;
 }
 maxSum(a, i);

}
