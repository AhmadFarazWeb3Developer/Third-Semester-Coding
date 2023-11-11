#include <iostream>
using namespace std;

class Queue
{
public:
    int* arr;
    int size;
    int forward;
    int backward;
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        forward = backward = 0;
    }
    void insert(int data)
    {
        if (isFull())
        {
            cout << "\nQueue is Full" << endl;
        }
        else {
            arr[forward] = data;
            forward++;
        }
    }
    void remove()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty" << endl;
        }
        else
        {
            arr[backward] = 0;
            backward++;
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty " << endl;
        }
        else
        {
            cout << "\nPeek is : " << arr[backward] << endl;

        }
    }
    bool isFull()
    {
        if (forward == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
    {

        if (forward == backward)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
    void Size() {
        if (isEmpty())
        {
            cout << "\nQueue is Empty " << endl;
        }
        else {

            cout << "\nSize of Queue is " << forward << endl;
        }
    }


    void Display()
    {
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "    ";
        }
    }
};

int main()
{

    Queue queue(5);
    queue.insert(10);
    queue.insert(11);
    queue.insert(12);
    queue.insert(13);
    queue.insert(14);
    queue.Display();

    queue.peek();
    queue.remove();


    queue.Display();
    queue.peek();
    queue.remove();


    queue.Display();
    queue.peek();
    queue.remove();
    queue.Display();
    queue.peek();
    queue.remove();

    queue.Display();
    queue.peek();
    queue.remove();
    queue.Display();
    queue.peek();
    queue.remove();
}
