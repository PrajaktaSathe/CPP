#include <iostream>
using namespace std;

// class for individual node (you can also use struct)
class node {
    public:
    int data; // to store information/element
    node *next; // points to the location of the next element
};

// class for performing operations on linked list -
class linked_list {
public:
    node *head, *tail; // creating head and tail nodes
    // constructor which initializes an empty linked list
    linked_list() {
        // both head and tail are initialized to null pointer, since both lead to nowhere
        head = nullptr;
        tail = nullptr;
    }
    void add_node(int); // function to add node
    void display(); // function to display linked list elements
    void delete_node(int); // function to delete elements of the linked list
};

void linked_list :: add_node(int key) {
    node *temp = new node; // create temp node
    temp -> data = key; 
    temp -> next = nullptr;
    if (head == nullptr) {
        head = temp;
        tail = temp;
    }
    else {
        tail -> next = temp;
        tail = tail -> next;
    }
    cout << key << " added to linked list!" << endl;
}

void linked_list :: display() {
    struct node *n;
    if (head == nullptr) {
        cout << "Linked list is empty!" << endl;
    }
    else {
        n = head;
        while (n != nullptr) {
            cout << n -> data << " ";
            n = n -> next;
        }
    }
}

void linked_list :: delete_node(int d) {
    if (head == nullptr) {
        cout << "Linked list is empty!" << endl;
    }
    else {
        node *temp = head;
        if (temp -> data == d) {
            temp = temp -> next;
            head = temp;
            return;
        }
        while (temp) {
            if (temp -> data == d) {
                temp -> data = temp -> next -> data;
                temp -> next = temp -> next -> next;
                break;
            }
            temp = temp -> next;
        }
        cout << endl << d << " is deleted from the linked list!" << endl;
    }
}

int main()
{
    linked_list l;
    l.add_node(3);
    l.add_node(10);
    l.add_node(20);
    l.add_node(30);
    l.display();
    l.delete_node(20);
    l.display();
    return 0;
}
