#include <bits/stdc++.h>
using namespace std;

struct queue1 {
  int front, rear, cap, size, arr[];
  queue1(int c) {
    arr[c];
    cap = c;
    front = -1;
    rear=-1;
    size = 0;
  }
  void enqueue() {
    if (isFull()) {
      printf("\nThe queue is full\n");
      return;
    }
    if (front == -1 && rear == -1) {
      front = 0;
      rear = 0;
    } else {
      rear = rear + 1;
    }
    int x;
    printf("Enter the element\n");
    scanf("%d", &x);
    arr[rear] = x;
    size++;
  }

  void dequeue() {
    if (isEmpty()) {
      printf("The queue is empty");
      return;
    }
    if (front == rear) {
      front = -1;
      rear = -1;
    } else {
      front = front + 1;
    }
    size--;
  }
  void getFront() {
    if (isEmpty())
      printf("Empty");
    else {
      printf("the ele at front is: %d", arr[front]);
    }
  }
  void getRear() {
    if (isEmpty())
      printf("Empty");
    else {
      printf("the ele at rear is: %d", arr[rear]);
    }
  }
  bool isEmpty() { return size == 0; }
  bool isFull() { return size == cap; }
  int qsize() { return size; }
};

main() {
  int c;
  printf("Enter the capacity\n");
  scanf("%d", &c);
  struct queue1 q(c);
  int ch;
  while (1) {
    printf("\n1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display size\n");
    printf("4.Display Front\n");
    printf("5.Display Rear\n");
    printf("6.Exit\n");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      q.enqueue();
      break;
    case 2:
      q.dequeue();
      break;
    case 3:
      printf("\nThe current size of queue is: %d", q.qsize());
      break;
    case 4:
      q.getFront();
      break;
    case 5:
      q.getRear();
      break;
    case 6:
      exit(0);
    default:
      printf("Incorrect choice \n");
    }
  }
}