#include<iostream>
using namespace std;
// declaring Node of type class
class Node {
public:
	int data;
	Node* nextAddress;
	// constructor
	Node(int data) {
		this->data = data;
		this->nextAddress = NULL;
	}
};
// stack class declartion
class Stack {
	Node* top;
public:
	// constructor
	Stack() {
		top = NULL;
	}
	// pushing data to stack on top node
	void Push(int data) {
		// Allocating memory to new data
		Node* temp = new Node(data);
		temp->data = data;
		temp->nextAddress = top;
		top = temp;
	}
	// pop element from top
	void Pop() {
		Node* temp;
		if (top == NULL) {
			cout << "\nStack is empty : ";
		}
		else {
			temp = top;
			cout << "\nData " << temp->data << " removed\n";
			top = top->nextAddress;
			delete temp;
		}
	}
	// used for giving top element of node
	void Top() {
		if (top == NULL) {
			cout << "\nStack is empty";
		}
		else {

			cout << "\nTop data is : " << top->data;
		}
	}
	// displaying all elements
	void Display() {
		Node* temp;
		if (top == NULL) {
			cout << "Stack is empty ";
		}
		else {
			temp = top;
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->nextAddress;
			}
		}
	}
};
int main() {

	Stack stack;
	int n, data;
	char ch;
	// do-while condition
	do {

		cout << "\nEnter Numeric values ";
		cout << "\n1 -> Push";
		cout << "\n2 -> Pop";
		cout << "\n3 -> Get Top";
		cout << "\n4 -> Display";
		cout << "\nEnter number : ";
		cin >> n;
		// condition for push
		if (n == 1) {
			int n;
			cout << "\nHow many elements do you want to push : ";
			cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "Enter Element no " << i + 1 << " : ";
				cin >> data;
				stack.Push(data);
			}
		}
		// condition for pop
		else if (n == 2) {
			stack.Pop();
		}
		// condition for top element getting
		else if (n == 3) {
			stack.Top();
		}
		// condtion for getting all elements displaying
		else if (n == 4) {
			stack.Display();
		}
		// condition for invalid value insertion
		else {
			cout << "Select valid numeric value \n";
		}

		cout << "\nEnter Y for more operation N for termination : ";
		cin >> ch;
	} while (ch != 'N');

	cout << "Program terminated";

}
