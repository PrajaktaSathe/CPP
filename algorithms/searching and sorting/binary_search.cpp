// Program to implement binary search -
#include <iostream>
using namespace std;

// class for storing functions and variables for performing binary search operations - 
class binarySearch {
    public: 
    int arr[50], i, n, left, right, mid, key;
    // function to get elements from the user -
    void get_element() {
        cout << "Enter the number of elements: ";
        cin >> n;
        for (i = 0; i < n; i++) {
            cout << "Enter number: ";
            cin >> arr[i];
        }
        cout << "Enter the element that you want to search: ";
        cin >> key;
    }
    // function to find element using binary search -
    void find() {
            left = 0; // position of leftmost element initially
            right = n - 1; // position of rightmost element initially
            mid = (left + right)/2; // position of middle element initially
            while (left <= right) {
                if (arr[mid] < key) {
                    left = mid + 1;
                }
                else if (arr[mid] == key) {
                    cout << "Number found at index: " << mid << endl;
                    break;
                }
                else {
                    right = mid - 1;
                }
                mid = (left + right)/2;
            }
            if (left > right) {
                cout << "Number not found in array.";
            }
    }
};

int main() {
    binarySearch b;
    b.get_element();
    b.find();
}