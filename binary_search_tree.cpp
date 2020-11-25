/*
Lab Assignment 5 : Binary Search Tree:
Implement binary search tree and perform following operations:
a) Insert (Handle insertion of duplicate entry) (DONE)
b) Delete (DONE)
c) Search (DONE)
d) Display tree (Traversal) - 3  Recursive; Implement only 1 Non-recursive (DONE)
e) Display - Depth of tree (DONE)
f) Display - Mirror image (DONE)
g) Create a copy
h) Display all parent nodes with their child nodes
i) Display leaf nodes (DONE)
j) Display tree level wise
(Note: Insertion, Deletion, Search and Traversal are compulsory, from rest of operations, perform
Any three)
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;
    node () {
        data = 0;
        left = right = NULL;
    }
};

class binarySearchTree {
public:
    node *root = NULL;
    void insert_node(int); // to insert element in binary search tree
    bool search_node(int, node*); // to search for a particular element
    bool search_node(); // helper function to search for node
    class node *delete_node(node *, int); // to delete node
    void delete_node_1(); // helper function to delete node
    void inorder(node *); // for inorder traversal of tree
    void preorder(node *); // for preorder traversal of tree
    void postorder(node *); // for postorder traversal of tree
    void display(); // to display elements of bst
    void display_leaf_nodes(node *); // to display leaf nodes
    void display_leaf_nodes_1(); // helper function for displaying leaf nodes
    void mirror_img(node *); // to display mirror image of tree
    void mirror_img_1(); // helper function to display mirror image of tree
    int display_depth(node *); // to display depth of bst
    void display_depth_1(); // helper function to display depth of bst
    class node *minKey(node *curr) {
        while (curr -> left != nullptr) {
            curr = curr -> left;
        }
        return curr;
    }
};

void binarySearchTree :: insert_node(int key) {
    // to insert an element if the tree is empty -
    if (root == NULL) {
        node *temp = new node(); // create new temporary node
        temp -> data = key; // assign key to data field of temp node
        temp -> left = temp -> right = NULL; // make right and left fields as null
        cout << "\nElement " << key << " is inserted!" << endl;
        cout << temp -> data << endl;
        root = temp; // assign temp node as root
        return;
    }
    node *temp1 = new node();
    temp1 = root;
    while(true) {
        // to insert element as left child of parent node -
        // check if key is less than or equal to element in data field -
        if (key < temp1 -> data || key == temp1 -> data) {
            // check if left child is present or not
            if (temp1 -> left == NULL) {
                temp1 -> left = new node; // create new node as left child of temp node
                temp1 = temp1 -> left; // assign the newly created node as temp
                temp1 -> data = key; // assign key to data field of temp node
                temp1 -> left = NULL; // assign left as NULL
                temp1 -> right = NULL; // assign right as NULL
                cout << "\nElement " << key << " inserted!" << endl;
                break;
            }
            // check if left child is present or not
            else if (temp1 -> left != NULL) {
                temp1 = temp1 -> left;
            }
        }
        // to insert element as right child of parent node -
        // check if key is greater than element in data field -
        else if (key > temp1 -> data) {
            // check if right child is present -
            if (temp1 -> right == NULL) {
                temp1 -> right = new node;
                temp1 = temp1 -> right;
                temp1 -> data = key;
                temp1 -> left = NULL;
                temp1 -> right = NULL;
                cout << "\nElement " << key << " inserted!" << endl;
                break;
            }
            // check if right child is present -
            else if (temp1 -> right != NULL) {
                  temp1 = temp1 -> right;
            }
        }
    }
    inorder(root); // to display elements
    cout << endl;
}

void binarySearchTree :: inorder(node *p) {
    // check if p is null
    if (p != nullptr) {
        inorder(p -> left); // function on left child
        cout << p -> data << " "; // print data
        inorder(p -> right); // function on right child
    }
}

void binarySearchTree :: preorder(node *p) {
    // check if p is null
    if (p != nullptr) {
        cout << p -> data << " "; // print data
        preorder(p -> left); // function on left child
        preorder(p -> right); // function on right child
    }
}

void binarySearchTree :: postorder(node *p) {
    // check if p is null
    if (p != nullptr) {
        postorder(p -> left); // function on left child
        postorder(p -> right); // function on right child
        cout << p -> data << " "; // print data
    }
}

void binarySearchTree :: display() {
    int ch;
    do {
        cout << "\nEnter 1 for inorder traversal, 2 for preorder traversal, 3 for postorder traversal, 4 to exit: ";
        cin >> ch;
        switch (ch) {
        case 1:
            if (root == nullptr) {
                cout << "BST is empty!" << endl;
                return;
            }
            inorder(root); // for inorder traversal of tree
            break;
        case 2:
            if (root == nullptr) {
                cout << "BST is empty!" << endl;
                return;
            }
            preorder(root); // for preorder traversal of tree
            break;
        case 3:
            if (root == nullptr) {
                cout << "BST is empty!" << endl;
                return;
            }
            postorder(root); // for postorder traversal of tree
            break;
        default:
            if (ch != 4) {
                cout << "Invalid Input!" << endl;
            }
        }
    } while (ch != 4);
}

void binarySearchTree :: display_leaf_nodes(node *root) {
    if (!root) {
        cout << "BST is empty!" << endl;
        return;
    }
    // if left child and right child both are null, it means that the node is a leaf node
    if (!root -> left && !root -> right) {
        cout << root -> data << " "; // print element in the data field
        return;
    }
    // check if left child is present
    if (root -> left) {
        display_leaf_nodes(root -> left);
    }
    // check if right child is present
    if (root -> right) {
        display_leaf_nodes(root -> right);
    }
}

void binarySearchTree :: display_leaf_nodes_1() {
    if (root != nullptr) {
        cout << "Displaying leaf nodes of bst: ";
    }
    display_leaf_nodes(root);

}

void binarySearchTree :: mirror_img(node *root) {
    // check if root is null/bst is empty
    if (root == nullptr) {
        return;
    }
    mirror_img(root -> left); // repeat on left child
    mirror_img(root -> right); // repeat on right child
    swap(root -> left, root -> right); // swap left and right
}

void binarySearchTree :: mirror_img_1() {
    // check if bst is empty
    if (root == nullptr) {
        cout << "BST is empty!" << endl;
        return;
    }
    cout << "Displaying mirror image of bst: " << endl;
    mirror_img(root); // to perform operation
    inorder(root); // to display elements inorder
}

class node *binarySearchTree :: delete_node(node *root, int key) {
    // check if binary search tree is present -
    if (root == nullptr) {
        return root;
    }
    // check if data field is less than key
    if (root -> data < key) {
        root -> right = delete_node(root -> right, key);
    }
    // check if data field is greater than key
    else if (root ->data > key) {
        root ->left = delete_node(root ->left, key);
    }
    // otherwise do the following
    else {
        // check if pointers to left and right children are null
        if (root -> left == nullptr && root ->right == nullptr) {
            free(root); // free the memory allocated to root node
            return nullptr;
        }
        // check if only left child is null
        else if (root -> left == nullptr) {
            class node *temp = root -> right;
            free(root); // free the memory
            return temp;
        }
        // check if only right child is null
        else if (root -> right == nullptr) {
            class node *temp = root -> left;
            free(root); // free the memory
            return temp;
        }
        else {
            class node* minimumKey = minKey(root -> right);
            root -> data = minimumKey -> data;
            root -> right = delete_node(root -> right, minimumKey -> data);
        }
    }
    return root;
}

void binarySearchTree :: delete_node_1() {
    int val1;
    cout << "Enter the element that you want to delete: ";
    cin >> val1;
    int pre = search_node(val1, root);
    if (pre == 1) {
        delete_node(root, val1);
        cout << val1 << " is deleted!" << endl;
    }
    else {
        cout << "Element not present to delete!" << endl;
    }
}

bool binarySearchTree :: search_node(int key, node *curr) {
    bool ans = false;
    if (curr == nullptr) {
        cout << "Element not found!" << endl;
        return false;
    }
    // if key is equal to the element in the data field, element is found
    if (key == curr -> data) {
        cout << "Element found!" << endl;
        return true;
    }
    // if key is less than element in the data field, repeat process on left child
    else if (key < curr -> data) {
        ans = search_node(key, curr -> left);
    }
    // if key is greater than element in the data field, repeat process on right child
    else {
        ans = search_node(key, curr -> right);
    }
    return ans;
}

bool binarySearchTree :: search_node() {
    int key;
    cout << "Enter element to search for: ";
    cin >> key;
    // check if root is null
    if (root == nullptr) {
        cout << "BST is empty!" << endl;
        return false;
    }
    else {
        return search_node(key, root);
    }
}

int binarySearchTree :: display_depth(node *root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        // l_depth is the depth of the left child
        int l_depth = display_depth(root -> left);
        // r_depth is the depth of the right child
        int r_depth = display_depth(root -> right);
        // check if l_depth is greater than r_depth
        if (l_depth > r_depth) {
            // if yes, return l_depth + 1
            return (l_depth + 1);
        }
        // if r_depth is greater than or equal to l_depth
        else {
            return (r_depth + 1);
        }
    }
}

void binarySearchTree :: display_depth_1() {
    int d = display_depth(root);
    if (d == 0) {
        cout << "BST is empty!" << endl;
    }
    else {
        cout << "Depth of binary search tree is: " << d - 1 << endl;
    }
}

int main() {
    int choice, val, key;
    binarySearchTree obj;
    do {
        cout << "\nWHAT WOULD YOU LIKE TO DO? \n1: Insert node, \n2: Display element(s), \n3: Search for an element, \n4: Delete an element, \n5: Display leaf node(s), \n6: Display mirror image of tree, \n7: Display depth of tree, \n8: Exit: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter element: ";
            cin >> val;
            obj.insert_node(val);
            break;
        case 2:
            obj.display();
            cout << endl;
            break;
        case 3:
            obj.search_node();
            break;
        case 4:
            obj.delete_node_1();
            break;
        case 5:
            obj.display_leaf_nodes_1();
            break;
        case 6:
            obj.mirror_img_1();
            break;
        case 7:
            obj.display_depth_1();
            break;
        default:
            if (choice != 8) {
                cout << "Invalid Input!" << endl;
            }
        }
    } while (choice != 8);
    return 0;
}
