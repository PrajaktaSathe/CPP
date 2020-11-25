#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

// class created for storing information of tree node -
class tnode {
  public:
  tnode *left; // stores left node location
  char data; // stores data
  tnode *right; // stores right node location
};

// class created for storing information of stack node -
class stacknode {
  public:
    tnode *data;
    int flag;
};

// class created for stack operations -
class my_stack {
  public:
  int top; // stored top location
  // constructor for initializing top to -1 -
  my_stack() {
    top = -1;
  }
  tnode *data1[100]; // array for storing elements of tree node
  stacknode data2[100];
  // function to push element of tree node into stack -
  void push(tnode *x) {
    data1[++top] = x;
  }
  // function to push element of stack node into stack -
  void push(stacknode x) {
    data2[++top] = x;
  }
  // function to pop element of tree -
  tnode *pop() {
    return data1[top--];
  }
  // function to pop element of stack node -
  stacknode pop1() {
    return data2[top--];
  }
  // function to check if empty -
  int isEmpty() {
    if (top == 0) {
      return 1;
    }
    return 0;
  }
};

class expressionTree {
  public:
  tnode *root = new tnode;
  my_stack s; // object of stack class created
  void createExpTreePost(); // function to create expression tree from postfix expression
  void createExpTreePre(); // function to create expression tree from prefix expression
  int validatePost(char exp[]); // function to validate postfix expression
  int validatePre(char exp[]); // function to validate prefix expression
  void traverseInorder(tnode *); // function to traverse tree inorder (without recursion)
  void recursiveInorder(tnode *); // function to traverse tree inorder (recursively)
  void inorder();
  void traversePreorder(tnode *); // function to traverse tree preorder (without recursion)
  void recursivePreorder(tnode *); // function to traverse tree preorder (recursively)
  void preorder();
  void traversePostorder(tnode *); // function to traverse tree postorder (without recursion)
  void recursivePostorder(tnode *); // function to traverse tree postorder (recursively)
  void postorder();
};

void expressionTree :: createExpTreePost() {
  char exp[100]; // array to store expression
  int validation;
  do {
    cout << "Enter postfix expression: ";
    cin >> exp;
    validation = validatePost(exp);
    if (validation != 1) {
      cout << "Invalid postfix expression!" << endl;
    }
  } while(validation != 1);

  for (int i = 0; exp[i] != '\0'; i++) {
    // check if it is a number or alphabet (operand) -
    if (isalnum(exp[i])) {
      tnode *temp1 = new tnode; // create new temporary node
      temp1 -> data = exp[i]; // assign element to data field of temp node
      temp1 -> right = temp1 -> left = NULL; // assign left and right values of node to NULL
      s.push(temp1); // push temp node into stack
    }
    else {
      // check if it is an operator -
      if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^') {
        tnode *temp2 = new tnode; // create new temp node
        temp2 -> data = exp[i]; // assign operator to data field of temp node
        temp2 -> right = s.pop(); // pop element from stack and assign to right child of temp node
        temp2 -> left = s.pop(); // pop element from stack and assign to left child of temp node
        s.push(temp2); // push temp node into stack
        root = temp2; // make temp root as root
      }
    }
  }
  cout << "Expression tree created from postfix expression." << endl;
}

void expressionTree :: createExpTreePre() {
  char exp[100]; // array for storing expression
  char e[100];
  int validation;
  do {
    cout << "Enter prefix expression: ";
    cin >> exp;
    validation = validatePre(exp);
    if (validation != 1) {
      cout << "Invalid prefix expression." << endl;
    }
  } while (validation != 1);

  int i, j, l = strlen(exp);
  for (i = 0, j = l - 1; j >= 0; i++, j--)
    e[i] = exp[j];
  e[i] = '\0';
  for (i = 0; e[i] != '\0'; i++) {
    // to check if operand -
    if (isalnum(e[i])) {
      tnode *temp1 = new tnode;
      temp1 -> data = e[i];
      temp1 -> left = temp1 -> right = NULL;
      s.push(temp1);
    }
    // for operators -
    else {
      if (e[i] == '+' || e[i] == '-' || e[i] == '*' || e[i] == '/' || e[i] == '^') {
        tnode *temp2 = new tnode;
        temp2 -> data = e[i];
        temp2 -> left = s.pop();
        temp2 -> right = s.pop();
        s.push(temp2);
        root = temp2;
      }
    }
  }
  cout << "Expression tree created from prefix expression." << endl;
}

int expressionTree :: validatePost(char exp[]) {
  int counter = 0;
  int i;
  for (i = 0; exp[i] != '\0'; i++) {
    if (isalnum(exp[i])) {
      counter++;
    }
    else {
      counter--;
      counter--;
      counter++;
    }
  }
  if (counter == 1) {
    return 1;
  }
  else {
    return 0;
  }
}

int expressionTree :: validatePre(char exp[]) {
  int counter = 1, flag = 0;
  int i;
  for (i = 0; exp[i] != '\0'; i++) {
    if (isalnum(exp[i])) {
      counter--;
      if (counter < 0) {
        flag = 1;
        break;
      }
    }
    else {
      counter++;
      if (counter < 0) {
        flag = 1;
        break;
      }
    }
  }
  if (counter == 0) {
    return 1;
  }
  else {
    return 0;
  }
}

void expressionTree :: traverseInorder(tnode *root) {
  stack<tnode*> stack;

	// start from root node (set current node to root node)
	tnode *curr = root;

	// if current node is null and stack is also empty, we're done
	while (!stack.empty() || curr != nullptr) {
		// if current node is not null, push it to the stack (defer it)
		// and move to its left child
		if (curr != nullptr) {
			stack.push(curr);
			curr = curr -> left;
		}
    // else if current node is null, we pop an element from the stack,
		// print it and finally set current node to its right child
		else {
			curr = stack.top();
			stack.pop();
			cout << curr -> data;

			curr = curr -> right;
		}
	}
}

void expressionTree :: recursiveInorder(tnode *root) {
  if (root == NULL) {
    return;
  }
  recursiveInorder(root -> left);
  cout << root -> data;
  recursiveInorder(root -> right);
}

void expressionTree :: inorder() {
  int choice;
  do {
    cout << "\nEnter 1 for non-recursive, 2 for recursive, 3 to exit: ";
    cin >> choice;
    switch (choice) {
      case 1:
      cout << "Non-recursive inorder tree traversal: ";
      traverseInorder(root);
      cout << endl;
      break;
      case 2:
      cout << "Recursive inorder tree traversal: ";
      recursiveInorder(root);
      cout << endl;
      break;
      default:
      if (choice != 3)
      cout << "Invalid Input!" << endl;
    }
  } while (choice != 3);
  cout << endl;
}

void expressionTree :: traversePreorder(tnode *root) {
    // check if root is null -
    if (root == NULL)
        return;
    stack<tnode *> stack;
    stack.push(root);
    while (!stack.empty()) {
        tnode *curr = stack.top();
        stack.pop();
        cout << curr -> data;
        if (curr -> right) {
            stack.push(curr -> right);
        }
        if (curr -> left) {
            stack.push(curr -> left);
        }
    }
}

void expressionTree :: recursivePreorder(tnode *root) {
  if (root == NULL)
    return;
  cout << root -> data;
  recursivePreorder(root -> left);
  recursivePreorder(root -> right);
}

void expressionTree :: preorder() {
  int choice;
  do {
    cout << "\nEnter 1 for non-recursive, 2 for recursive, 3 to exit: ";
    cin >> choice;
    switch (choice) {
      case 1:
      cout << "Non-recursive preorder tree traversal: ";
      traversePreorder(root);
      cout << endl;
      break;
      case 2:
      cout << "Recursive preorder tree traversal: ";
      recursivePreorder(root);
      cout << endl;
      break;
      default:
      if (choice != 3)
        cout << "Invalid Input!" << endl;
    }
  } while (choice != 3);
  cout << endl;
}

void expressionTree :: traversePostorder(tnode *root) {
  stacknode st;
  tnode *p;
  while (root != NULL) {
    st.data = root;
    st.flag = 0;
    s.push(st);
    root = root -> left;
  }
  while (!s.isEmpty()) {
    st = s.pop1();
    if (st.flag == 0) {
      st.flag = 1;
      s.push(st);
      root = st.data;
      root = root -> right;
      while (root != NULL) {
        st.data = root;
        st.flag = 0;
        s.push(st);
        root = root -> left;
      }
    }
    else {
      p = st.data;
      cout << p -> data;
    }
  }
}

void expressionTree :: recursivePostorder(tnode *root) {
  if (root != NULL) {
    recursivePostorder(root -> left);
    recursivePostorder(root -> right);
    cout << root -> data;
  }
}

void expressionTree :: postorder() {
  int choice;
  do {
    cout << "\nEnter 1 for non-recursive, 2 for recursive, 3 to exit: ";
    cin >> choice;
    switch (choice) {
      case 1:
      cout << "Non-recursive postorder tree traversal: ";
      traversePostorder(root);
      cout << endl;
      break;
      case 2:
      cout << "Recursive postorder tree traversal: ";
      recursivePostorder(root);
      cout << endl;
      break;
      default:
      if (choice != 3)
        cout << "Invalid Input!" << endl;
    }
  } while (choice != 3);
  cout << endl;
}

int main() {
  expressionTree obj;
  int ch;
  char ch1;
  do {
    cout << "Enter 1 to enter postfix expression, 2 to enter prefix expression, 3 to quit: ";
    cin >> ch;
    switch (ch) {
      case 1:
      obj.createExpTreePost();
      do {
        cout << "Enter a for postorder traversal, b for preorder traversal, c for inorder traversal, d to exit: ";
        cin >> ch1;
        switch (ch1) {
          case 'a':
          obj.postorder();
          break;
          case 'b':
          obj.preorder();
          break;
          case 'c':
          obj.inorder();
          break;
          default:
          if (ch1 != 'd') {
          cout << "Invalid Input!" << endl;
          }
        }
      } while (ch1 != 'd');
      break;
      case 2:
      obj.createExpTreePre();
      do {
        cout << "Enter a for postorder traversal, b for preorder traversal, c for inorder traversal, d to exit: ";
        cin >> ch1;
        switch (ch1) {
          case 'a':
          obj.postorder();
          break;
          case 'b':
          obj.preorder();
          break;
          case 'c':
          obj.inorder();
          break;
          default:
          if (ch1 != 'd') {
            cout << "Invalid Input!" << endl;
          }
        }
      } while (ch1 != 'd');
      break;
      default:
      if (ch != 3) {
        cout << "Invalid Input!" << endl;
      }
    }
  } while (ch != 3);
}
