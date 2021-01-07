// Program to implement linear search algorithm -
#include <iostream>
using namespace std;

// class for storing functions and variables to perform linear search -
class linearSearch {
    public:
    int arr[50], i, key, n;
    // function to get elements - 
    void get_element() {
        cout << "Enter number of elements: ";
        cin >> n;
        for (i = 0; i < n; i++) {
            cout << "Enter element: ";
            cin >> arr[i];
        }
    }
    // function to find element from the array using linear search - 
    void find() {
        cout << "Enter the number which is to be searched: ";
        cin >> key;
        for (i = 0; i < n; i++) {
            // check if element in the array is equal to the element which the user wants to search for - 
            if (arr[i] == key) {
                cout << "Number found at index: " << i << endl;
                break;
            }
        }
        // if array is completely done traversing through - 
        if (i == n) {
            cout << "Number not found in array." << endl;
        }
    }
};

int main() {
    linearSearch l;
    l.get_element();
    l.find();
}
