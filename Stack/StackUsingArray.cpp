#include<iostream>
using namespace std;
// declaring class named stack
class Stack {
// static array
		int array[5];
		int top;

	public:
		// constructor
		Stack()
		{
			top=-1;
		}
// push element to the top
		void Push(int data)
		{
			if(top>=4) {
				cout<<"\nStack is full";
			}
			else {

				array[++top]=data;
				cout<<"\nData "<<data<<" added";
			}

		}
// pop element from the top
		void Pop()
		{
			if(top<0) {
				cout<<"\nStack is Empty";
			}
			else {
				cout<<"\nData "<<array[top--]<<" removed ";
			}
		}

// return the element of top
		void Top()
		{
			if(top<0) {
				cout<<"\nStack is Empty";

			}
			else {

				cout<<"\nTop element is : "<<array[top];
			}
		}
// used for printing al elements on stack
		void allElements()
		{
			for(int i=0; i<5; i++) {
				cout<<array[i]<<" ";
			}
		}
};
int main()
{
	Stack stack ;
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);
// stack is full
	stack.Push(60);
// top element is returned
	stack.Top();
// remove element from top
	stack.Pop();
// printing all elements of array
	stack.allElements();


}
