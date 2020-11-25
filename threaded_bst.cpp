// DSA Lab Assignment 6 -
#include <iostream>
using namespace std;

// class created for storing contents of node -
class Node {
public:
    int data; // to store data
    Node *left, *right; // pointers to left and right children nodes
    int l_flag, r_flag; // left and right flags
    // constructor for initializing variables -
    Node() {
        data = 0;
        left = right = nullptr;
        l_flag = r_flag = 0;
    }
};

// class for threaded binary search tree -
class tbst {
public:
    Node *root; // create a new pointer to node as root
    // constructor for initializing variables -
    tbst() {
        root = new Node();
        root -> data = 0;
        root -> left = root;
        root -> right = root;
        root -> l_flag = 0;
        root -> r_flag = 1;
    }
    void insert(int); // function to insert an element into the tbst
    void inorder(); // function to traverse the tree inorder
    void preorder(); // function to traverse the tree preorder
    Node *inorder_ele(Node *);
    Node *preorder_ele(Node *);
};

void tbst :: insert(int n) {
    // check if root is the only node -
    if (root -> left == root && root -> right == root) {
        Node *temp = new Node(); // create new temporary node
        temp -> data = n; // assign n to data value of temp node
        temp -> left = root -> left;
        temp -> right = root -> right;
        temp -> l_flag = root -> l_flag;
        temp -> r_flag = 0; // flag will be 0 as there is no successor
        root -> left = temp; // temp node will take the place of left child of root
        root -> l_flag = 1; // flag will be 1 as predecessor is present
        return;
    }
    // if above condition is false, then do the following -
    Node *node = new Node;
    node = root -> left;
    while (true) {
        // check if element in the data field is less than n -
        if (node -> data < n) {
            Node *temp = new Node(); // create temp node
            temp -> data = n;
            if (node -> r_flag == 0) {
                temp -> left = node;
                temp -> l_flag = 0;
                temp -> right = node -> right;
                temp -> r_flag = node -> r_flag;
                node -> right = temp;
                node -> r_flag = 1;
                return;
            }
            // else go to the right child of node -
            else {
                node = node -> right;
            }
        }
        // check if element in the data field is greater than n -
        else if (node -> data >= n) {
            Node *temp = new Node(); // create a temp node
            temp -> data = n;
            if (node -> l_flag == 0) {
                temp -> left = node -> left;
                temp -> right = node;
                temp -> l_flag = node -> l_flag;
                temp -> r_flag = 0;
                node -> left = temp;
                node -> l_flag = 1;
                return;
            }
            // else go to the left child of node -
            else {
                node = node -> left;
            }
        }
    }
}

void tbst :: inorder() {
    Node *node_1;
    node_1 = root -> left;
    // continue until left flag is 1
    while (node_1 -> l_flag == 1) {
        node_1 = node_1 -> left; // go to left child
    }
    // continue until node is not the same as root -
    while (node_1 != root) {
        cout << " " << node_1 -> data; // display element
        node_1 = inorder_ele(node_1);
    }
}

Node *tbst :: inorder_ele(Node *n) {
    if (n -> r_flag == 0) {
        return (n -> right);
    }
    else {
        n = n -> right;
    }
    while (n -> l_flag == 1) {
        n = n -> left;
    }
    return (n);
}

void tbst :: preorder() {
    Node *node_2;
    node_2 = root -> left;
    while (node_2 != root) {
        cout << " " << node_2 -> data;
        node_2 = preorder_ele(node_2);
    }
}

Node *tbst :: preorder_ele(Node *n) {
    if (n -> l_flag == 1) {
        return (n -> left);
    }
    while (n -> r_flag == 0) {
        n = n -> right;
    }
    return (n -> right);
}

int main() {
    tbst tree;
    int num, i, val;
    cout << "How many elements do you want to insert: ";
    cin >> num;
    for (i = 0; i < num; i++) {
        cout << "Enter element: ";
        cin >> val;
        tree.insert(val);
    }
    int choice;
    do {
        cout << "Enter 1 for inorder traversal, 2 for preorder traversal, 3 to exit: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nInorder Traversal of tbt: " << endl;
            tree.inorder();
            cout << endl;
            break;
        case 2:
            cout << "\nPreorder Traversal of tbt: " << endl;
            tree.preorder();
            cout << endl;
            break;
        default:
            if (choice != 3) {
                cout << "Invalid input!" << endl;
            }
        }
    } while (choice != 3);
    return 0;
}
