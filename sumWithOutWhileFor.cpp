#include<iostream>
using namespace std;
//this if from http://zhedahht.blog.163.com/blog/static/2541117420072915131422/
class Temp
{
public:
      Temp() { ++ N; Sum += N; }

      static void Reset() { N = 0; Sum = 0; }
      static int GetSum() { return Sum; }

private:
      static int N;
      static int Sum;
};

int Temp::N = 0;
int Temp::Sum = 0;

int solution1_Sum(int n)
{
      Temp::Reset();

      Temp *a = new Temp[n];
      delete []a;
      a = 0;

      return Temp::GetSum();
}
int main() {
    cout<<solution1_Sum(9);
    return 1;
}
//another nice implementation, using virtual
class A;
A* Array[2];

class A
{
public:
      virtual int Sum (int n) { return 0; }
};

class B: public A
{
public:
      virtual int Sum (int n) { return Array[!!n]->Sum(n-1)+n; }
};

int solution2_Sum(int n)
{
      A a;
      B b;
      Array[0] = &a;
      Array[1] = &b;

      int value = Array[1]->Sum(n);

      return value;
}

//more nicer!!
typedef int (*fun)(int);

int solution3_f1(int i)
{
      return 0;
}

int solution3_f2(int i)
{
      fun f[2]={solution3_f1, solution3_f2};
      return i+f[!!i](i-1);
}
