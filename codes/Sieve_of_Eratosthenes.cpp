/*the sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.*/
#include<iostream>
#include<conio.h>
using namespace std;
int prime(int n)         // To check if a number is prime
{
    int i=2;
    while(i<=n/2)
    {
        if(n%i==0)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
int main()
{
    int n;
    cout<<"Enter the max value(n)-";
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(prime(i)==0)
        {
            cout<<i<<" ";                // Printing a number if it is prime.
        }
    }
    return 0;
}
