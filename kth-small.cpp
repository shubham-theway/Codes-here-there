#include <iostream>

using namespace std;

namespace _ksmall
{
	void swp(int &a, int&b)
	{
		int t = a;
		a = b;
		b = t;
	}

	void kheapify(int *a, int n)
	{
		int l, r;
		int i = 0;
		bool change = false;
		while (true)
		{
			l = i * 2 + 1;
			r = i * 2 + 2;
			if (l < n)
			{
				if (r < n)
				{
					if (a[i] > a[l] && a[r]>a[l])
					{
						swp(a[i], a[l]);
						change = true;
					}
					else if (a[i] > a[r] && a[l] > a[r])
					{
						swp(a[i], a[r]);
						change = true;
					}
				}
				else if (a[i] > a[l])
				{
					swp(a[i], a[l]);
					change = true;
				}
			}
			else
			{
				if (r<n && a[i]>a[r])
				{
					swp(a[i], a[r]);
					change = true;
				}
			}
			if (!change)
				break;
		}
	}

	int ksmall(int *a, int n, int k)
	{
		int l;
		int r;

		for (int i = 0; i < k; i++)
		{
			swp(a[0], a[n - i - 1]);
			kheapify(a, n - i - 1);
		}
		return a[0];
	}

	// 7 3 9 1 8 6 2


	void kbuildheap(int *a, int n)
	{
		int l, r;
		for (int i = n / 2; i >= 0; i--)
		{
			kheapify(a, i);
		}

		/*for (int i=0;i<n/2;i++)
		{
		l = i * 2 + 1;
		r = i * 2 + 2;
		if (l < n)
		{
		if (r < n)
		{
		if (a[i] > a[l] && a[r]>a[l])
		swp(a[i], a[l]);
		else if (a[i] > a[r] && a[l] > a[r])
		swp(a[i], a[r]);
		}
		else if (a[i] > a[l])
		swp(a[i], a[l]);
		}
		else
		{
		if (r<n && a[i]>a[r])
		{
		swp(a[i], a[r]);
		}
		}
		}*/
	}

	int partition(int arr[], int low, int hi)
	{
		int p = arr[hi];
		int j = low - 1;
		for (int i = low; i < hi; i++)
		{
			if (arr[i] < p)
			{
				swap(arr[i], arr[++j]);
			}
		}
		swap(arr[hi], arr[++j]);
		return j;
	}

	int kSmallquick(int arr[], int low,int hi,int k)
	{
		if (low < hi)
		{
			int p = partition(arr, low, hi);
			if (k == p)
				return arr[k];
			else if (k<p)
				kSmallquick(arr, low, p-1,k);
			else
				kSmallquick(arr, p+1, hi,k);
		}
		return arr[k];
	}

}


using namespace _ksmall;
int main4525hyr()
{
	//int n=8;
	int a[] = { 5, 21, 14, 7, 11, 9, 6, 8 }; 
	//5,6,7,8,9,11,14,21
	int k;
	cin >> k;
	//kbuildheap(a, n);
	//ksmall(a, n,k);

	cout<<kSmallquick(a, 0, 7,k);
	cout << endl;

	system("pause");
	return 0;
}