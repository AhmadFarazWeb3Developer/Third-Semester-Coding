#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node* nextAddress;
  Node(int data) {
    this->data = data;
    nextAddress = NULL;
  }
  ~Node() {

    if (this->nextAddress != NULL) {
      this->nextAddress = NULL;
      delete nextAddress;
    }
    cout << "\nNode is deleted with : " << this->data << endl;
  }
};

class Queue {
public:
  Node* front;
  Node* rare;
  Queue() {
    front = rare = NULL;
  }

  void enQueue(int data) {
    Node* tempNode = new Node(data);
    if (rare == NULL) {
      front = rare = tempNode;
    }
    else {
      rare->nextAddress = tempNode;
      rare = tempNode;
    }
  }
  void deQueue() {

    if (front == NULL) {
      rare = NULL;
    }
    else {
      Node* tempNode = front;
      front = front->nextAddress;
      delete tempNode;
    }
  }
  void queueFront() {

    Node* tempNode = front;

    if (rare == front) {
      cout << "\nQueue is empty" << endl;
    }
    else {
      cout << "\nElement at front of queue is : " << tempNode->data << endl;
    }
  }
  void Print() {
    Node* tempNode = front;
    if (tempNode != NULL) {
      cout << "Elements of the Queue are ";
      cout << "\n-----------------------------------"
        "------------"
        << endl;
      while (tempNode != NULL) {
        cout << tempNode->data << " ";
        tempNode = tempNode->nextAddress;
      }
      cout << "\n-----------------------------------"
        "------------"
        << endl;
    }
    else {
      cout << "\nQueue is Empty" << endl;
    }
  }
};
int main() {
  Node* node = new Node(0);
  Queue queue;
  queue.enQueue(34);
  queue.enQueue(35);
  queue.enQueue(36);
  queue.enQueue(37);
  queue.enQueue(38);
  queue.enQueue(39);
  queue.enQueue(40);
  queue.Print();
  queue.queueFront();
  queue.deQueue();
  queue.deQueue();
  queue.deQueue();
  queue.deQueue();
  queue.deQueue();
  queue.deQueue();
  queue.deQueue();
  queue.deQueue();

  queue.queueFront();
  queue.Print();
}
