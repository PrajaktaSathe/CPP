#include<iostream>
#include<conio.h>
using namespace std;
int gcd(int a,int b)
{
    int c;
    for(int i=1;i<=(a>b?b:a);i++) // To execute the loop x times where x is the smaller number
    {
        if(a%i==0 && b%i==0)
        {
            c=i;                    // Assigning the given factor to c
        }
    }
    return c;
}
int main()
{
    int a,b;
    cout<<"Enter the values whose GCD you wish to find-";
    cin>>a>>b;
    cout<<"GCD is "<<gcd(a,b);
    return 0;
}
