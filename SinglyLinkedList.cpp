#include <iostream>
using namespace std;

// Declaring Node Class
class Node {
public:
  int data;
  Node *nextAddress;
  // constructor for getting datting data
  Node(int data) {
    this->data = data;
    this->nextAddress = NULL;
  }
  // Destructor
  ~Node() {
    int value = this->data;
    if (this->nextAddress != NULL) {
      this->nextAddress = NULL;
      delete nextAddress;
    }
    cout << "\nNode of data " << value << " is removed " << endl;
  }
};

//  Function for  inserting element
void insertAtHead(Node *&headNode, int data) {
  Node *tempNode = new Node(data);
  tempNode->nextAddress = headNode;
  headNode = tempNode;
}

// Function for insertion at Tail
void insertAtTail(Node *&TailNode, int data) {
  Node *tempNode = new Node(data);
  TailNode->nextAddress = tempNode;
  TailNode = TailNode->nextAddress;
}

// Function for insertion of Node at any given position
void insertAtPosition(Node *&tailNode, Node *&headNode, int position,
                      int data) {

  // insert at head
  if (position == 1) {
    insertAtHead(headNode, data);
    return;
  }

  // Insertion at any position
  Node *tempNode = headNode;
  int count = 1;
  while (count < position - 1) {
    tempNode = tempNode->nextAddress;
    count++;
  }
  Node *newNode = new Node(data);
  newNode->nextAddress = tempNode->nextAddress;
  tempNode->nextAddress = newNode;
  // Insertion at tail
  if (tempNode->nextAddress == NULL) {
    insertAtTail(tailNode, data);
  }
}

// Function for deletion of node
void deleteNode(Node *&headNode, int position) {
  int nodesSize = 0;
  Node *tempNode = headNode;
  while (tempNode != NULL) {
    nodesSize++;
    tempNode = tempNode->nextAddress;
  }
  if (position > 0 && position <= nodesSize) {
    if (position == 1) {
      Node *tempNode = headNode;
      headNode = headNode->nextAddress;
      tempNode->nextAddress = NULL;
      delete tempNode;
    } else {
      Node *currentNode = headNode;
      Node *previousNode = NULL;
      int count = 1;
      while (count < position) {
        previousNode = currentNode;
        currentNode = currentNode->nextAddress;
        count++;
      }
      previousNode->nextAddress = currentNode->nextAddress;
      currentNode->nextAddress = NULL;
      delete currentNode;
    }
  } else {
    cout << "\nThere is no Node at " << position << " position\n";
    return;
  }
}

// Function for Searching a node
void searchNode(Node *headNode, int num) {
  Node *tempNode = headNode;
  bool found = false;
  while (tempNode != NULL) {
    if (tempNode->data == num) {
      found = true;
      break;
    }
    tempNode = tempNode->nextAddress;
  }
  if (found) {
    cout << "The number " << num << " is found." << endl;
  } else {
    cout << "The number " << num << " is not found." << endl;
  }
}

// Function for sorting a list
void sortListAscending(Node *&headNode) {
  Node *currentNode = headNode;
  Node *forwardNode = NULL;
  int tempData;
  if (headNode == NULL) {
    return;
  } else {
    while (currentNode != NULL) {
      // Node index will point to node next to current
      forwardNode = currentNode->nextAddress;
      while (forwardNode != NULL) {
        // If current node's data is greater than index's node data, swap the
        // data between them
        if (currentNode->data > forwardNode->data) {
          tempData = currentNode->data;
          currentNode->data = forwardNode->data;
          forwardNode->data = tempData;
        }
        forwardNode = forwardNode->nextAddress;
      }
      currentNode = currentNode->nextAddress;
    }
  }
}

// Function for printing
void print(Node *&headNode) {
  // decaring a temproray node which will point
  // to head then to next nodes in loop
  Node *tempNode = headNode;
  while (tempNode != NULL) {
    cout << tempNode->data << "  ";   // printing the data of current node
    tempNode = tempNode->nextAddress; // pointing the address of next node
  }
}

int main() {
  // declaring object od class Node with data
  Node *node = new Node(0);
  Node *headNode = node;
  Node *tailNode = node;
  char check;
  do {
    cout << "\n::::Welcome to work with Linked List::::";
    cout << "\n:                                      :";
    cout << "\n:   Choose Your Operation Options      :";
    cout << "\n:   1 ->   Insertion At Head           :";
    cout << "\n:   2 ->   Insertion at Tail           :";
    cout << "\n:   3 ->   Insertion at Position       :";
    cout << "\n:   4 ->   Delete a Node               :";
    cout << "\n:   5 ->   Search a Node               :";
    cout << "\n:   6 ->   Sort by Ascending           :";
    cout << "\n:   7 ->   Print Linked List           :";
    cout << "\n::::::::::::::::::::::::::::::::::::::::";
    cout << "\n\nEnter Operation Number  :  ";
    int number;
    cin >> number;
    switch (number) {
    //  Case 1 for insertion data at head
    case 1: {
      int n;
      char chk;
      do {
        cout << "Enter number at head   :  ";
        cin >> n;
        insertAtHead(headNode, n);
        cout << "Enter Y for new Node / N for not  :  ";
        cin >> chk;
      } while (chk != 'N');
      break;
    }
    // case 2 is for insertion data a tail
    case 2: {
      int n;
      cout << "\nEnter Number at tail  :  ";
      cin >> n;
      insertAtTail(tailNode, n);
      print(headNode);
      break;
    }
    // case 3 insertion at position
    case 3: {
      int n, p;
      cout << "\nEnter Position  :  ";
      cin >> p;
      cout << "Enter Number for position  :  ";
      cin >> n;
      insertAtPosition(tailNode, headNode, p, n);
      print(headNode);
      break;
    }
    // case 4 is for delation of a data
    case 4: {
      int p;
      cout << "\nEnter Node position  :  ";
      cin >> p;
      deleteNode(headNode, p);
      break;
    }
    case 5: {
      // case 5 is for Searching a data
      int n;
      cout << "\nEnter Number to be searched  :  ";
      cin >> n;
      searchNode(headNode, n);
      break;
    }
    case 6: {
      // case 6 is for sorting a linked list
      cout << "\nBefore Sorting  :  ";
      print(headNode);
      cout << "\nAfter Sorting  :  ";
      sortListAscending(headNode);
      print(headNode);
      break;
    }
    //  case 7 is for printing all nodes data in linked list
    case 7: {
      cout << "\nAll Nodes of Linked List are  :  ";
      print(headNode);
      break;
    }
    }
    cout << "\n\nDo you want to perform more operation ? ";
    cout << "\n\nEnter Y for yes and N not no  :  ";
    cin >> check;
  } while (check != 'N');
  { cout << "You have terminated the Program"; }
}
