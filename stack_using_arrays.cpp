// Implementation of stack using arrays -
#include <iostream>
#define MAX 25
using namespace std;

class stacks{
    int top; // to store the position of the topmost element
public:
    int numbers[MAX]; // stack array
    void push(int); // function to push elements into the stack
    int pop(); // function to pop the last element
    void display(); // function to display the elements
    // constructor for initializing the position of topmost element -
    stacks() {
        top = -1;
    }
};

void stacks :: push(int x) {
    // check if capacity of stack is full - 
    if (top >= MAX) {
        cout << "Stack overflow!" << endl;
    }
    else {
        numbers[++top] = x;
        cout << "Inserted element: " << x  << endl;
    }
}

int stacks :: pop() {
    // check if stack is empty - 
    if (top < 0) {
        cout << "Stack underflow!" << endl;
    }
    else {
        int d = numbers[top--];
        cout << "Popped element: " << d << endl;
        return d;
    }
}

void stacks :: display() {
    if (top < 0) {
        cout << "Stack is empty!" << endl;
        return;
    }
    else {
        for (int i = top; i >= 0; i--) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    stacks s;
    int ch;
    // menu-driven program - 
    do {
        cout << "Enter 1 to push, 2 to pop, 3 to display, 4 to exit: ";
        cin >> ch;
        switch (ch) {
        case 1:
            int n;
            cout << "Enter the number that you want to push into the stack: ";
            cin >> n;
            s.push(n);
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
            cout << "Invalid Input!" << endl;
        }
    } while (ch != 4);
    return 0;
}
