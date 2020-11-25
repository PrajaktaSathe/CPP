#include <iostream>
#include <string>
using namespace std;
#define SIZE 6

// Class for circular queue -
class CQueue {
    public:
    // Structure Student for storing student details -
    struct Student {
    int rno; // To store serial number
    string name; // To store name
    double sgpa; // To store sgpa
    };
    Student temp;
    Student arr[SIZE]; // Array for storing student details
    int front, rear;
    // Constructor used for initializing front and rear pointers to -1 -
    CQueue() {
        front = -1;
        rear = -1;
    }
    int isFull(); // Function to check if queue is full
    int isEmpty(); // Function to check if queue is empty
    void enqueue(); // Function to perform enqueue operation
    int dequeue(); // Function to perform dequeue operaton
    void display(); // Function to display elements
    void display_rev(); // Function to display elements from last node
    void display_inter(); // Function to display elements from any intermediate node
};

int CQueue :: isFull() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) {
        return 1;
    }
    return 0;
}

int CQueue :: isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void CQueue :: enqueue() {
  string value;
  int roll;
  double sgpaval;
    // Check if queue is full -
    if (isFull())
      cout << "Queue is full. No more admissions can be allocated!\n" << endl;

    else {
      cout << "Enter name: ";
      cin >> value;
      cout << "Enter serial no.: ";
      cin >> roll;
      cout << "Enter SGPA: ";
      cin >> sgpaval;
        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        arr[rear].name = value;
        arr[rear].rno = roll;
        arr[rear].sgpa = sgpaval;
        cout << "\nStudent inserted in queue is: "<< value << endl;
    }
}

int CQueue :: dequeue() {
    string variable;
    // Check if queue is empty -
    if (isEmpty()) {
        cout<<"Queue is empty!"<<endl;
        return -1;
    }
    else {
        variable = arr[front].name;
        if (front == rear) {
            front = rear = -1;
    }
    else {
      front = (front + 1) % SIZE;
    }
    cout << "\nAdmission allocated to : "<< variable << endl;
    return 1;
  }
}

void CQueue :: display() {
    int i;
    // Check if queue is empty -
    if (isEmpty())
       cout << "Queue is empty!" << endl;
    else {
        cout << "Sr.No." << "\t" << "Name" << "\t\t" << "SGPA" << endl;
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            cout << arr[i].rno << "\t" << arr[i].name << "\t" << arr[i].sgpa << endl;
        }
    cout << arr[i].rno << "\t" << arr[i].name << "\t" << arr[i].sgpa << endl;
  }
}

void CQueue :: display_rev() {
    int i;
    // Check if queue is empty -
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
    }
    else {
        cout << "Sr.No." << "\t" << "Name" << "\t\t" << "SGPA" << endl;
        for (i = rear; i != rear - 1; i = (i + 1) % SIZE) {
            cout << arr[i].rno << "\t" << arr[i].name << "\t" << arr[i].sgpa << endl;
        }
        cout << arr[i].rno << "\t" << arr[i].name << "\t" << arr[i].sgpa << endl;
    }
}

void CQueue :: display_inter() {
    int i;
    int temp;
    // Check if queue is empty -
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
    }
    else {
        cout << "Enter node from which you want to display elements: ";
        cin >> temp;
        cout << "Sr.No." << "\t" << "Name" << "\t\t" << "SGPA" << endl;
        for (i = temp; i != temp - 1; i = (i + 1) % SIZE) {
            cout << arr[i].rno << "\t" << arr[i].name << "\t" << arr[i].sgpa << endl;
        }
        cout << arr[i].rno << "\t" << arr[i].name << "\t" << arr[i].sgpa << endl;
    }
}

int main() {
  CQueue obj;
  int choice;
  cout << "Welcome to the student admission portal!" << endl;
  do {
    cout << "\nEnter 1 to enqueue" << endl;
    cout << "Enter 2 to dequeue" << endl;
    cout << "Enter 3 to display from last node" << endl;
    cout << "Enter 4 to display from intermediate node" << endl;
    cout << "Enter 5 to stop: ";
    cin >> choice;
    switch (choice) {
    case 1:
      obj.enqueue();
      obj.display();
      break;
    case 2:
      obj.dequeue();
      obj.display();
      break;
    case 3:
      obj.display_rev();
      break;
    case 4:
      obj.display_inter();
      break;
    default:
        if (choice != 5) {
            cout << "Invalid Input!" << endl;
        }
    }
  } while (choice != 5);
  cout << "End of program!" << endl;
  return 0;
}
