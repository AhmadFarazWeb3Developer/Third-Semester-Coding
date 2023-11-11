
// Linear search using linked list

#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *nextAddress;
	Node(int data)
	{
		this->data = data;
		nextAddress = NULL;
	}
	~Node()
	{
		if (this->nextAddress != NULL)
		{
			this->nextAddress = NULL;
			delete nextAddress;
		}
	}
};
void insertNode(Node *&head, int data)
{

	Node *tempNode = new Node(data);
	tempNode->nextAddress = head;
	head = tempNode;
}

void print(Node *head)
{
	Node *&tempNode = head;
	while (tempNode != NULL)
	{
		cout << tempNode->data << endl;
		tempNode = tempNode->nextAddress;
	}
	delete tempNode;
}

void Search(Node *&head, int element)
{
	Node *tempNode = head;
	while (tempNode != NULL)
	{
		if (tempNode->data == element)
		{
			cout << tempNode->data << " element found in linked list" << endl;
			return;
		}
		tempNode = tempNode->nextAddress;
	}
	cout << element << " element not found in linked list";
}
int main()
{
	Node *node = new Node(12);
	Node *head = node;
	insertNode(head, 11);
	insertNode(head, 12);
	insertNode(head, 13);
	insertNode(head, 14);
	insertNode(head, 15);
	print(head);
	Search(head, 13);
	Search(head, 10);
}
