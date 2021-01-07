// Program to implement bubble sort in C++
#include <iostream>
using namespace std;

// class to store functions and variables for performing bubble sort -
class bubbleSort {
  public:
  int i, j, n, temp, arr[20];
  void get_elements(); // function to get elements from the user
  void sort(); // function to sort elements using bubble sort
  void display(); // function to display sorted elements
};

void bubbleSort :: get_elements() {
  cout << "Enter the number of elements: ";
  cin >> n;
  for (i = 0; i < n; i++) {
    cout << "Enter number: ";
    cin >> arr[i];
  }
}

void bubbleSort :: sort() {
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[i]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void bubbleSort :: display() {
  cout << "Displaying sorted elements: " << endl;
  for (i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  bubbleSort b;
  b.get_elements();
  b.sort();
  b.display();
}