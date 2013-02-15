#include<iostream>
using namespace std;

void atoii (char *s) {
    char *p = s;
    int neg=1;
    cout<<*p;
    if (*p == '-') {
        neg = -1;
        p++;
    }
    cout<<*p;
    int num = 0;
    while (*p!='\0') {
        if ((*p >='0') && (*p <= '9')) {
            num+= num*10 + *p-'0';
        } else {
        cout<<"illegle string";
        }
    }
    cout << num * neg;
}



int main() {
    char *c;
    cin>>c;
    atoii(c);
    return 0;
}
