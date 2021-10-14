#include<iostream>
using namespace std;
void selectionSort(int n ,int array[]){
    for(int i=0;i<n;i++){
            int max = 0;
            for(int j=1 ; j<=n-1-i;j++){
                if(array[j]>array[max]){
                    max=j;
                }
            }
            int temp = array[max];
            array[max]=array[n-1-i];
            array[n-1-i]=temp;
        }
}
void display(int n,int array []){
    cout<<"The sorted array is ";
    for(int i = 0 ; i<n ; i++){
        cout<<array[i]<<" ";
    }
}
int main(){
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size; //taking size of the array
    int array[size];
    cout<<"Enter elements of the array"<<endl;
    for(int i = 0 ; i<size ; i++){
        cin>>array[i];
    }
    selectionSort(size,array);
    display(size,array);
    return 0;
}
