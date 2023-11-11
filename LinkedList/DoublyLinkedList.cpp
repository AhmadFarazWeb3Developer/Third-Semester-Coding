#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* nextAddress;
  Node* prevAddress;
  // default constructor
  Node() {
    this->data = 0;
    this->nextAddress = NULL;
    this->prevAddress = NULL;
  }
  // parametarized constructor
  Node(int data) {
    this->data = data;
    this->nextAddress = NULL;
    this->prevAddress = NULL;
  }
  // Destructor
  ~Node() {
    if (nextAddress != NULL) {
      delete nextAddress;
      nextAddress = NULL;
    }
    cout << "\nNode with data : " << this->data << " is deleted" << endl;
  }
};
// function for diplaying the linkedlist
void Display(Node* head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->nextAddress;
  }
}
//  insertion at head
void insertAtHead(Node*& head, int data) {
  Node* temp = new Node(data);
  temp->nextAddress = head;
  head->prevAddress = temp;
  head = temp;
}
// insertion at tail
void insertAtTail(Node*& tail, int data) {
  Node* temp = new Node(data);
  tail->nextAddress = temp;
  temp->prevAddress = tail;
  tail = temp;
}
// insertion at any position
void insertAtPosition(Node*& tail, Node*& head, int position, int data) {
  // insertion at head
  if (position == 1) {
    insertAtHead(head, data);
    return;
  }
  Node* temp = head;
  int count = 1;
  while (count < position && temp != NULL) {
    temp = temp->nextAddress;
    count++;
  }
  if (temp == NULL) {
    cout << "Invalid position." << endl;
    return;
  }
  // insertion at tail
  if (temp->nextAddress == NULL) {
    insertAtTail(tail, data);
    return;
  }
  // creating node for insertion
  Node* nodeToInsert = new Node(data);
  nodeToInsert->nextAddress = temp->nextAddress;
  nodeToInsert->prevAddress = temp;
  temp->nextAddress->prevAddress = nodeToInsert;
  temp->nextAddress = nodeToInsert;
}

// deletion of node
void deleteNode(Node*& head, int position) {
  if (position == 1) {
    Node* temp = head;
    if (head->nextAddress != NULL) {
      head->nextAddress->prevAddress = NULL;
    }
    head = temp->nextAddress;
    temp->nextAddress = NULL;
    delete temp;
    return;
  }

  Node* currentNode = head;
  int count = 1;
  while (currentNode != NULL && count < position) {
    currentNode = currentNode->nextAddress;
    count++;
  }

  if (currentNode == NULL) {
    cout << "Invalid position." << endl;
    return;
  }

  Node* prevNode = currentNode->prevAddress;
  Node* nextNode = currentNode->nextAddress;

  prevNode->nextAddress = nextNode;
  if (nextNode != NULL) {
    nextNode->prevAddress = prevNode;
  }

  currentNode->nextAddress = NULL;
  currentNode->prevAddress = NULL;
  delete currentNode;
}

// ------------------------------------
int main() {
  Node* node = new Node();
  Node* head = node;
  Node* tail = node;

  insertAtHead(head, 12);
  insertAtHead(head, 13);
  insertAtHead(head, 14);

  insertAtTail(tail, -1);

  insertAtPosition(tail, head, 2, 10);
  insertAtPosition(tail, head, 7, 120);
  Display(head);

  deleteNode(head, 3);
  Display(head);
}
