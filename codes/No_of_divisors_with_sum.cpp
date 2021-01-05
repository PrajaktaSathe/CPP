/*Program to find all possible positive divisors of a number and printing their sum as well as their number along with the divisors.    */
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n,b=1,sum=0;       // For each number is divisor to itself
    cout<<"Enter the number whose divisors you wish to find- ";
    cin>>n;
    sum=n;                 // For each number is divisor to itself
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
            b+=1;
            sum+=i;
        }
    }
    cout<<n;
    cout<<"\nThe number of divisors- "<<b<<" and sum is - "<<sum;
    return 0;
}
