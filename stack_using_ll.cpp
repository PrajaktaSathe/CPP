// Following program demonstrates the implementation of stack using linked lists - 
#include <iostream>
using namespace std;

// structure for storing node of stack
struct node {
    int data;
    node *next;
};

// class for performing operations on the stack - 
class stack {
    public:
    struct node *head = NULL; // initializing head node to null
    void push(); // function to push an element into the stack
    void pop(); // function to pop the topmost element from the stack
    void display(); // function to display elements of the stack
};

void stack :: push() {
    int num;
    cout << "Enter number to push element into stack: ";
    cin >> num;
    node *temp = new node; // creating a new temporary node
    temp -> data = num; // assigning num value to data field of temp node
    temp -> next = head;
    head = temp;
}

void stack :: pop() {
    // check if stack is empty - 
    if (head == NULL) {
        cout << "Stack underflow!" << endl;
    }
    else {
        cout << "Popped element: " << head -> data << endl;
        head = head -> next;
    }
}

void stack :: display() {
    node *temp = new node;
    if (head == NULL) {
        cout << "Stack is empty!" << endl;
        return;
    }
    else {
        temp = head;
        while (temp != NULL) {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
}

int main() {
    stack s;
    int ch;
    // implementing menu-driven program - 
    do {
        cout << "Enter 1 to push, 2 to pop, 3 to display, 4 to exit: ";
        cin >> ch;
        switch (ch) {
            case 1:
            s.push();
            break;
            case 2:
            s.pop();
            break;
            case 3:
            s.display();
            break;
            case 4:
            cout << "End of program!" << endl;
            break;
            default:
            cout << "Invalid input!" << endl;
        }
    } while (ch != 4);
    return 0;
}
