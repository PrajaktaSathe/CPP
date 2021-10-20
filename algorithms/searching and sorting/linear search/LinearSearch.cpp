#include<iostream>
#include<conio.h>
using namespace std;

int main(){
   int arraySize, data,j;
      cout<<"\nEnter Array Size :- ";
   cin>>arraySize;
   int a[arraySize];
   cout<<"\nEnter Array Elements :- ";
   for(int i = 0; i < arraySize; i++){
        cin>>a[i];
   }
   cout<<"\nYour Array elements are :- \n";
   for(int i = 0; i < arraySize; i++){
        cout<<" "<<a[i]<<" ";
   }
   cout<<"\n\n";
   cout<<"Enter Data You want to Search :- ";
   cin>>data;
   for(j = 0; j < arraySize; j++){
    if(a[j] == data){
        cout<<"\nElement found at index :- "<<j;
        break;
    }
   }
   if(j == arraySize){
        printf("Element is not found");
   }
   getch();
}
