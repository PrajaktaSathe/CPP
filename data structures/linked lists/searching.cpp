//this program searches a linked list
// by traversing the whole linked list through iteration

#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  node *next;
};

// Utility function
// it inserts nodes at the back of the linked list

void push_back(node *&head, int val)
{
  node* newnode=new node;
  node* temp=head;
  newnode->data= val;
  newnode->next=NULL;
  if(head==NULL)
  {
    head=newnode;
    return;
  }
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=newnode;
  return;
}

// display the linked list

void display(node *& head)
{
  node* temp=head;
  while(temp->next!=NULL)
  {
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  if(temp->next==NULL)
    cout<<temp->data<<"->NULL";
}

// search function to search val

void searching(node *&head , int val)
{
  node* temp=head;
  bool flag=1;
  while(temp->data!=val)
  {
    temp=temp->next;
    if(temp==NULL)
    {
      flag=0;
      break;
    }
  }
  if(flag==1)
    cout<<"ELEMENT FOUND";
  else
    cout<<"ELEMENT NOT FOUND";
}

//Driver code

int main()
{
  node * llist=NULL;
  int n;
  cout<<"Enter size:";
  cin>>n;
  cout<<"Enter elements:";
  for(int i=0;i<n;i++)
  {
    int v;
    cin>>v;
    push_back(llist, v);
  }
  display(llist);
  int k;
  cout<<"\nEnter number to search:";
  cin>>k;
  searching(llist,k);
}
  
  
  
