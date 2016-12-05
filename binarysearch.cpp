#include <iostream>

using namespace std;


void binarySearch(int *ar,int len, int el,int *res)
{
	int i, j;
	int mid = len / 2;
	int low = 0;
	int high = len - 1;
	while (low<high)
	{
		if (ar[mid] == el)
		{
			*res = mid;
			return;
		}
		if (ar[mid] < el)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
		mid = (low + high) / 2;
	}
	*res = -1;
}

int main35()
{
	int size;
	cin >> size;
	int *ar = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> ar[i];
	}

	int el;
	cin>>el;

	int result;
	binarySearch(ar, size,el,&result);

	if (result < 0)
		cout << "not found\n";
	else
		cout << "found at index = " << result << endl;

	system("pause");
	return 0;
}