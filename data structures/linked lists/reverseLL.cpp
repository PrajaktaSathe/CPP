#include<iostream> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node* next; 
    Node (int data) 
    { 
        this->data = data; 
        next = NULL; 
    } 
}; 
  
struct LinkedList 
{ 
    Node *head; 
    LinkedList() 
    { 
        head = NULL; 
    } 
  
  
    /* reverse the linked list */
    void reverse() 
    { 
        // Initialize current, previous and 
        // next pointers 
        Node *current = head; 
        Node *prev = NULL, *next = NULL; 
  
  
        while (current != NULL) 
        { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev; 
    } 
  
    /*  print linked list */
    void print() 
    { 
        struct Node *temp = head; 
        while (temp != NULL) 
        { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
    } 
  
    void push(int data) 
    { 
        Node *temp = new Node(data); 
        temp->next = head; 
        head = temp; 
    } 
}; 

int main() 
{ 
    
    LinkedList ll; 
    ll.push(20); 
    ll.push(4); 
    ll.push(15); 
    ll.push(85); 
  
    cout << "Given linked list
"; 
    ll.print(); 
  
    ll.reverse(); 
  
    cout << "
Reversed Linked list
"; 
    ll.print(); 
    return 0; 
} 