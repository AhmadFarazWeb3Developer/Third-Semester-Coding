
// Binary search using Array

#include <iostream>
using namespace std;
void Search(int arr[], int size, int element)
{
	int start = 0;
	int end = size - 1;
	int mid = (start + end) / 2;
	while (start <= end)
	{
		if (arr[mid] == element)
		{
			cout << element << " found in array" << endl;
			return;
		}
		if (element > arr[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}
	cout << element << " not found in array" << endl;
}
int main()
{
	int oddArr[5] = { 11, 13, 15, 17, 20 };
	int evenArr[8] = { 2, 3, 5, 6, 8, 9, 10, 14 };
	Search(oddArr, 5, 20);
	Search(evenArr, 8, 2);
	Search(oddArr, 5, 100);
	Search(evenArr, 8, 0);
}
