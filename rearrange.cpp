#include<iostream>

using namespace std;

void rearrange(int a[], int n)
{
	int i = 0;
	int c = 0;
	
	int k;
	int p=0;
	c = a[0];
	k = a[c];
	while (i < n)
	{
		
		c = a[p];
		a[p] = k;
		//c = k;
		for (int j = 1; j < n; j++)
		{
			/*if (i>0 && j == 0)
				continue;*/
			if (a[j] == p)
			{
				p = j;
				break;
			}
		}
		k = c;
		//c = a[p];
		i++;
	}
}

int mai234n()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	rearrange(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}