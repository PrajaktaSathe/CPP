// Program to Demonstrate Implementation of Queue using Stacks
#include <iostream>
#include <stack>
using namespace std;

// A Class which uses 2 stacks to act as Queue.
class Queue {
public:
    stack <int> Stack1, Stack2;
    Queue() {
        // Initializing the stacks to be empty when the constructor gets called during Instantiation
        while (!Stack1.empty()) Stack1.pop();
        while (!Stack2.empty()) Stack2.pop();
    }
    
    // Push the element to back of the Queue
    void push(int x) {
        if (Stack1.empty() && !Stack2.empty()) {
            while (!Stack2.empty()) {
                Stack1.push(Stack2.top());
                Stack2.pop();
            }
        }
        Stack1.push(x);
    }
    
    // Pop the element from front of the Queue
    int pop() {
        while (!Stack1.empty()) {
            Stack2.push(Stack1.top());
            Stack1.pop();
        }
        int t = Stack2.top();
        Stack2.pop();
        return t;
    }
    
    // Get the Front/Peek element of the Queue
    int peek() {
        int t = this -> pop();
        Stack2.push(t);
        return t;
    }
    
    // A Function to check if the Queue is empty
    bool empty() {
        return (Stack1.empty() && Stack2.empty());
    }
};

int main() {
  
    Queue Q;

    // Adding two elements to the Queue
    Q.push(1);
    Q.push(2);
    Q.push(3);

    // Front element in the Queue
    cout << "Front element in the Queue = " << Q.peek() << "\n";

    // Popping an Element from the Queue
    Q.pop();
    
    // Front element in the Queue
    cout << "Front element in the Queue = " << Q.peek() << "\n";

    // Checking if Queue is Empty
    if (Q.empty()) {
        cout << "Queue is Empty\n";
    } else {
        cout << "Queue is Not Empty\n";
    }
   
}