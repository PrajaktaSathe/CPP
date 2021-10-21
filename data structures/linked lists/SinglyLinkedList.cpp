#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
struct node* root = NULL;
void append()
{
    int ele;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter element :- ";
    cin>>ele;
    temp -> data = ele;
    temp ->link = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while(p->link != NULL)
        {
            p = p -> link;
        }
        p -> link = temp;
    }
}
void length()
{
    int count = 0;
    struct node *temp;
    temp = root;
    while(temp != NULL)
    {
        count = count + 1;
        temp = temp -> link;
    }
    cout<<"Length is :- "<<count;
}
void inFirst()
{
    int ele;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter element :- ";
    cin>>ele;
    temp -> data = ele;
    temp -> link = root;
    root = temp;
}
void display()
{
    struct node* p;
    p = root;
    if(root == NULL)
    {
        cout<<"No elements";
    }
    else
    {
        while(p != NULL)
        {
            cout<<p -> data<<" ";
            p = p -> link;
        }
    }
}
void atMiddle()
{
    int data, findEle;
    struct node *temp, *p, *q;;
    temp = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter data :- ";
    cin>>data;
    temp -> data = data;
    p = root;
    cout<<"Enter element after which you want to insert :- ";
    cin>>findEle;
    while(p -> data != findEle)
    {
        p = p -> link;
    }
    q = p -> link;
    temp -> link = q;
    p -> link = temp;
    cout<<data<<" inserted successfully\n";
}
int main()
{
        int choice;
        do
        {
            cout<<"\n1.Append\n2.Length\n3.In First\n4.Display\n5.At Middle\n6.Exit\n";
            cout<<"Enter your choice :- ";
            cin>>choice;
            switch(choice)
            {
                case 1: append(); break;
                case 2: length(); break;
                case 3: inFirst(); break;
                case 4: display(); break;
                case 5: atMiddle(); break;
                case 6: exit(0);
                default: cout<<"Wrong input";
            }
        }while(choice != 6);
    getch();
}
