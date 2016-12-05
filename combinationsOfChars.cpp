#include "stdafx.h"

namespace _combination
{
	void combination(int arr[], int len, int r, int index, int data[], int i, vector<int>*v)
	{
		if (index == r)
		{
			for (int i = 0; i < r; i++)
				//cout << (char)data[i];
				v->push_back(data[i]);
			//cout << endl;
			return;
		}

		if (i >= len)
			return;

		data[index] = arr[i];
		combination(arr, len, r, index+1, data, i+1,v);

		combination(arr, len, r, index, data, i+1,v);
	}

	void print(int arr[], int len, const int r, vector<int>*v)
	{
		int *data=new int[r];
		combination(arr, len, r, 0, data, 0,v);
	}

}

using namespace _combination;
int main345t()
{
	int arr[] = { 'a', 'b', 'c', 'd' };
	vector<vector<int>> coll;
	for (int i = 1; i <= (sizeof(arr) / sizeof(int)); i++)
	{
		vector<int> v;
		print(arr, 4, i, &v);
		coll.push_back(v);
	}

	for (auto it = coll.begin(); it != coll.end(); it++)
	{
		for (auto iit = (*it).begin(); iit != (*it).end(); iit++)
		{
			cout << (char)(*iit)<<" ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}