#include<iostream>
using namespace std;
int fibonacciTerm(int n)
{
    if (n <= 1)     
        return n;      //returns 0 for n=0 and 1 for n=1
    return fibonacciTerm(n-1) + fibonacciTerm(n-2);
}
int main(){
    int n;
    cout<<"Enter the term of the fibonacci sequence whose value you want to find : ";
    cin>>n;
    int term = fibonacciTerm(n);
    cout<<"The "<<n<<" term of the fibonacci sequence is "<<term;
    return 0;
}
