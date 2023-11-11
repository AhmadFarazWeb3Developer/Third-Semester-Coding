
// Linear search using Array
#include <iostream>
using namespace std;

class Search
{
	int *arr;
	int Size;

public:
	Search(int size)
	{
		Size = size;
		arr = new int[size];
	}

	void searchElement(int element)
	{
		for (int i = 0; i < Size; i++)
		{
			if (arr[i] == element)
			{
				cout << "Element found: " << element << endl;
				return;
			}
		}
		cout << "Element Not found" << endl;
	}

	void creatArray()
	{
		cout << "\nEnter Elements for Array" << endl;
		for (int i = 0; i < Size; i++)
		{
			cout << "Enter " << i + 1 << " element : ";
			cin >> arr[i];
		}
	}
};

int main()
{
	int size;
	cout << "Enter Size for Array : ";
	cin >> size;

	Search *search = new Search(size);
	search->creatArray();

	int elt;
	cout << "\nEnter element to search : ";
	cin >> elt;
	search->searchElement(elt);

	delete search;
	return 0;
}
