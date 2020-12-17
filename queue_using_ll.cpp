// program to demonstrate implementation of queues using linked lists - 
#include <iostream>
using namespace std;

// structure for storing information of node of queue - 
struct node {
    int data;
    node *next;
};

// class for performing operations on the queue -
class queue {
    public:
    node *front; // front node
    node *rear; // rear node
    node *temp; // temp node
    void enqueue(); // function to enqueue/insert an element into the queue
    void dequeue(); // function to dequeue/remove the element from the front
    void display(); // function to display elements of the queue
    // constructor for initializing front and rear pointers to NULL
    queue() {
        front = rear = NULL;
    }
};

void queue :: enqueue() {
    int num;
    cout << "Enter the number you want to enqueue: ";
    cin >> num;
    // case where queue is empty
    if (rear == NULL) {
        rear = new node;
        rear -> data = num;
        rear -> next = NULL;
        front = rear;
    }
    // case where queue is not empty - 
    else {
        temp = new node;
        temp -> data = num;
        rear -> next = temp;
        if (front == NULL) {
            front = temp;
            rear = temp;
            front -> next = NULL;
            rear -> next = NULL;
        }
        else {
            rear -> next = temp;
            rear = temp;
            rear -> next = NULL;
        }
    }
}

void queue :: dequeue() {
    struct node *ptr; // temporary pointer
    if (front == NULL) {
        if (front == rear) {
            cout << "Queue is empty!" << endl;
        }
        else {
            cout << "Underflow condition!" << endl;
            return;    
        }
    }
    else {
        ptr = front;
        cout << "Deleted element: " << front -> data << endl;
        front = front -> next;
        free(ptr);
    }
}

void queue :: display() {
    node *temp = new node;
    temp = front;
    if (front == NULL) {
        cout << "Queue is empty!" << endl;
    }
    else {
        while (temp != NULL) {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
}

int main() {
    queue q;
    int ch;
    do {
        cout << "Enter 1 to emqueue, 2 to dequeue, 3 to display, 4 to exit: ";
        cin >> ch;
        switch (ch) {
            case 1:
            q.enqueue();
            break;
            case 2:
            q.dequeue();
            break;
            case 3:
            q.display();
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
